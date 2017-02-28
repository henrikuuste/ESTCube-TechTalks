# The Great Metaprogramming Conundrum

- What is **metaprogramming** anyway?
- Why do we need it?
- How do we use it?
- Would you be surprised to learn that **you** have been found guilty of metaprogramming?

Answer all these questions and more. This TechTalk will explain the basics of
metaprogramming and then promptly dive off the deep end into C++ land (with occasional
sidetracks into the lowlands of C and highlands Python).

We look at common C++ metaprogramming tecniques with use cases to show how any sane
person could have thought of these things. We take a peek at what is to come in future standards
and what clever people have done with metaprogramming libraries.

Topics will include such great things as
* Generic programming
* Generic lambdas
* Variadic templates
* Tag dispatching
* Reflection
* Registrars
* Serialization

## Organization

The talk will be very practical. We will start with code and end with code.
I will edit code live and people will have access to the same base code through github.

If you want to play along with everything, you need a good modern compiler like **gcc 6.3.0** or later.
New versions of clang should also work.

There are also several online compilers available such as
- http://cpp.sh/
- http://ideone.com/
- http://melpon.org/wandbox/

We'll see if I get around to testing those. But we will definitely make some use of
https://godbolt.org/ to look at what **really** happens to your code.