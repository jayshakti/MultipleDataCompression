MultipleDataCompression
=======================

MULTIPLE DATA COMPRESSION AND EXPANSION USING ITERATIVE TECHNIQUE
-----------------------------------------------------------------

Since we know that in almost all the devices there is memory constraint. So there should be judicious use of the available memory. So how to compress and expand the compressed data using iterative technique and save memory is implemented in this project.

**Compression:**
Since the size of char is 1 byte so it could be used to represent 256 different characters. But in how many of our files do we actually have 256 different characters . So taking the advantage over this fact we could actually compress our data.

The first step towards compressing data is to create a master array which contains the different characters that exists in our file. So if for example in our 100 character file there are only 15 different characters then master array would be of size 15. Then taking a step further in order to compress data we need to assign an index to each of the member of master array with minimum number of bits required to represent all of the members of the master array. In our case of 15 characters we could represent each member with only with 4-bits rather than 8-bits which were used earlier.

So after providing each member of the master array with a unique index of 4 bits each we move on to the next step. We then need to access each element of our text file and map that element with the master array and find out its unique index value. The value which we provided is of 4 bits so we could actually combine the index values of two elements and form an compressed byte which actually contains two of characters from the file in the space of 1 character. Thus effective we are saving 50% of our memory.

**De_compression:**
So by reversing this procedure we could revive all our original data from the compressed data using the key i.e. The master array which we have created earlier.

In this way we can use our storage device with small storage capability to store large amount of data.

# Commands to execute the project
- ./test
