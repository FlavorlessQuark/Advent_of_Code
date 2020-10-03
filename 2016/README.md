# Gotta go fast

## Reminder to self

Windows files have CRLF file endings and must be converted via `dos2unix [filename]`
Else some surprises may occur while parsing.

The python has

Need to Update aoc.h:

Fetch by word by line ();
	array of lists: Pros : easy to iterate. Only one call to malloc
					Cons : Need to know line count beforehand... Potentially would have to read file twice. Not very good for large files.

	lists of list : Pros : Only one file read is enough;
					Cons : A pain to iterate through; Multiple calls to malloc. More pointers than I'd like.

**Need to check something about unallocated memory**

*If a list pointer *lst has an adress 0x000001 , is it valid to have another pointer *lst1 such that *lst1 = lst + sizeof(lst)?*
*Would 0x000009 be a valid adress ? Or does it need to be allocated?*
*I have to test this in the void_sandbox but I think it will either result in segfault or memory corruption over time...*
