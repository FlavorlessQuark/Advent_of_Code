
## The Path of the Snake:

Thou shan't be afraid to *import*

If 't be true thy mind hast hought of it, then there exists an *import*

To reacheth true und'rstanding is to comprehend **[Comprehensions][0]**

Thou shalt know that -1 is indeed a valid index...

When thou discovers that *xrange* is faster than *range* for thy looping purposes, then thou shall soon earn thy Scale of Speed

If thy courage is great enough then thou may solve any problem with one line of **[regex][3]**

---
## Required modules

- Anytree
- Re
- Numpy

**Note**

- Most of these assume a new line a the end of the input file

## Import todo

People always ask where is day22, but not how is day22? Well day22 looks like a long complicated hassle and so I will leave it alone.
If it can't be done at least partially with math and / or requires actual simulation, I don't want anything to do with it.

- [x] **Day06**: Did somebody say [Hash_Table, Blessed Tool of the SpeedSeeker] ?
- [x] **Day08**: is written more like C. More slithery thinking is required
- [ ] **Day19**: Part2 is tricky. Can't be done with a tree (probably can but would take forever) Probably need to work backwards from solution back to e, inverting key with replacement. The input has a
pattern Rn..Y..Ar | Rn..Ar | or just random letters. The problem is solving it in a pythonic way...
- [ ] **Day20**: Trying to solve mathematically first... Checking for prime numbers might be a good solution here, though not very pythonic I feel. I might try to use lambad expressions more, or maybe I can
find some import that returns a list of factors. Snake over speed. Optimization will come when done in C...
---

## From knowledge import progress_report as pr

Comprehensions are perhaps the most useful things. They allow for a one time object allocation (instead of using, for example, repeated calls to append() which reallocates the object everytime). Though they must be kept relatively simple for readibility purposes...

I'm quite satisfied of my comprehensions so far, they are getting more complex but more straightforward.

Learned about enumerate, useful when making comprehensions out of file line numbers. Would be useful for Aunt Sue

Lambda expressions are something I have yet to utilize properly. I'm not sure why they would be used over regular functions. given that they are the same thing...

I should learn to use map(), though I have yet to find a use for it.
 ^ Found a use for it, see day 12. It works well with regex
---

### This is Sadly only for [python3][2] :(
	
Dictionaries can be considered a set and can have anything as a key... even another dictionary

Just like mathematical sets, union, interesections and differences can be performed... See **[Set][1]**

However, I am not sure why one would use a |= b instead of a.update(b) (a and b both being dictionaries)

Xrange is not supported on python 3 :(


[0]:https://docs.python.org/3/tutorial/datastructures.html?highlight=comprehension#list-comprehensions
[1]:https://docs.python.org/2/library/sets.html
[2]:https://www.python.org/dev/peps/pep-0584/#major-objections
[3]:https://docs.python.org/3/library/re.html
[4]:https://docs.python.org/3/reference/expressions.html
