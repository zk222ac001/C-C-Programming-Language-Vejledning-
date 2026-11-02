"""C++17 teaching examples: output, invalid constructs, and exception boundaries.
Run from any directory: python3 tests/test_oop_advanced.py
Requires g++ (or set CXX to a compatible compiler executable).
"""
from pathlib import Path
import os
import subprocess
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
CXX = os.environ.get('CXX', 'g++')
EXPECTED = {
 '01_medlemmer.cpp': 'Antal: 0\nA: 21\nB: 25\nAntal: 2\nAntal: 0\n',
 '02_referencer.cpp': 'Lokal kopi: 99\na: 20, b: 50\nLaest: 30\nDobbelt: 60\n',
 '03_livscyklus.cpp': '+ BaseA 7\n+ BaseB\n+ kamera\n+ motor\n+ Robot-krop\n- Robot-krop\n- motor\n- kamera\n- BaseB\n- BaseA\n',
 '04_diamant.cpp': 'Uden virtual: 1, 2\nMed virtual: 42, 42\n',
 '05_overloading.cpp': 'vis(int)\nvis(double)\nbland(int, double)\nbland(double, int)\n',
 '06_binding_slicing.cpp': 'Statisk: Dyr\nDynamisk: Vov\nVaerdi: Generisk lyd\nReference: Vov\n',
 '07_abstrakte_klasser.cpp': '12\n25\n',
 '08_operatorer.cpp': 'a + b = (4, 6)\na uændret = (1, 2)\na += b: (4, 6)\nKaede: (8, 9)\nInput: (5, 6)\nAfvist input, stadig: (5, 6)\n',
 '09_exceptions_raii.cpp': 'Hent laas\nHent fil\nFrigiv fil\nFrigiv laas\nSpecifik catch: Negativ maaling\nFortsætter\n',
 '10_genkast.cpp': 'Log i mellem\nYderst: Indeks 8 findes ikke\n',
 '11_constructor_fejl.cpp': '+ Del\nHelhed-krop starter\n- Del\nCatch: Kunne ikke starte\n',
 '12_noexcept.cpp': 'hent: true\nkanFejle: false\n',
}

class TeachingExamples(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory(prefix='cpp-oop-')
        self.work = Path(self.temp.name)
    def tearDown(self):
        self.temp.cleanup()
    def compile(self, sources, name='program'):
        out = self.work / name
        build = subprocess.run([CXX, '-std=c++17', '-Wall', '-Wextra', '-pedantic-errors',
                                *map(str, sources), '-o', str(out)],
                               capture_output=True, text=True, encoding='utf-8', timeout=30)
        return build, out
    def source(self, text, name='case.cpp'):
        p = self.work / name
        p.write_text(text, encoding='utf-8')
        return p
    def test_complete_examples(self):
        for name, expected in EXPECTED.items():
            with self.subTest(program=name):
                build, exe = self.compile([ROOT/'examples/oop-advanced'/name], name+'.bin')
                self.assertEqual(build.returncode, 0, build.stderr)
                self.assertEqual(build.stderr, '', 'Unexpected warning: '+build.stderr)
                run = subprocess.run([str(exe)], capture_output=True, text=True, encoding='utf-8', timeout=5)
                self.assertEqual(run.returncode, 0, run.stderr)
                self.assertEqual(run.stdout, expected)
    def test_intentionally_invalid_programs(self):
        cases = {
            'private': 'class A { int x=0; }; int main(){ A a; return a.x; }',
            'abstract': 'struct A { virtual void f()=0; }; int main(){ A a; }',
            'ambiguous': 'void f(int,double){} void f(double,int){} int main(){ f(1,1); }',
            'wrong_override': 'struct A { virtual void f() const {} }; struct B:A { void f() override {} }; int main(){}',
            'diamond': 'struct A { int x=0; }; struct B:A{}; struct C:A{}; struct D:B,C{}; int main(){ D d; return d.x; }',
            'legacy_throw': 'void f() throw(int) {} int main(){}',
        }
        for name, source in cases.items():
            with self.subTest(case=name):
                build, _ = self.compile([self.source(source)])
                self.assertNotEqual(build.returncode, 0, 'Invalid program unexpectedly compiled')
    def test_inline_across_translation_units(self):
        self.source('#pragma once\ninline int twice(int n){ return n*2; }\n', 'calc.hpp')
        a = self.source('#include "calc.hpp"\nint other(){ return twice(3); }', 'a.cpp')
        b = self.source('#include "calc.hpp"\nint other(); int main(){ return other()+twice(2)==10 ? 0 : 1; }', 'b.cpp')
        build, exe = self.compile([a,b])
        self.assertEqual(build.returncode, 0, build.stderr)
        self.assertEqual(subprocess.run([str(exe)], timeout=5).returncode, 0)
    def test_terminate_boundaries_in_isolated_processes(self):
        prefix = '#include <exception>\n#include <cstdlib>\n'
        programs = {
            'noexcept': 'void g(){ throw 1; } void f() noexcept { g(); } int main(){ std::set_terminate([]{std::_Exit(42);}); try{f();}catch(...){return 1;} }',
            'double_exception': 'struct Guard { ~Guard() noexcept(false){ throw 2; } }; int main(){ std::set_terminate([]{std::_Exit(42);}); try{ Guard g; throw 1; }catch(...){return 1;} }',
        }
        for name, body in programs.items():
            with self.subTest(boundary=name):
                build, exe = self.compile([self.source(prefix+body)])
                self.assertEqual(build.returncode, 0, build.stderr)
                self.assertEqual(subprocess.run([str(exe)], timeout=5).returncode, 42)

if __name__ == '__main__':
    unittest.main(verbosity=2)
