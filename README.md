# Homework 5 : File Systems
## Part 1 : Write to Journal
For this portion of the homework assignment, you will be editting the method write_to_journal().  This method is based the following:
- int txb_bytes : number of bytes in variable txb
- char* txb : transaction begin block of size txb_bytes
- int ibytes : number of bytes in variable i
- char* i : inode block of size ibytes
- int bbytes : number of bytes in variable b
- char* b : bitmap block of size bbytes
- int Db_bytes : number of bytes in variable Db
- char* Db : data block of size Db_bytes
- int txe_bytes : number of bytes in variable txe
- char* txe : transaction end block of size txe bytes

Edit this method to write all data to the file 'journal.txt'.  The data should be written to this file in the order in the following order: 
1. char* txb : transaction begin block of size txb bytes 
2. char* i : inode block of size ibytes
3. char* b : bitmap block of size bbytes
4. char* Db : data block of size Db bytes
5. char* txe : transaction end block of size txe bytes . 

Make sure to close the file before the method returns.
Hints :
- The method open(...) shoujld be used to open the file, returning a file descriptor
- When creating a file, you will need to pass permissions as the third argument (i.e. 0600)
- The method write(...) takes the file descriptor, size, and data to write to the file
- After writing to the file, be sure to call fsync() to force write to disk
- The method close(...) closes the file descriptor

## Part 2 : Checkpointing
For this part of the programming assignment, you will edit the method checkpoint(...), which is passed the following parameters : 
- int txe_bytes : number of bytes in variable txe
- char* txe : transaction end block of size txe bytes

Assuming all data has been written to the journal, the data should now be copied into it’s final location. This can be done with the following steps.
1. Open the file journal.txt and make sure that all data has been written to the journal
2. If the journal is incomplete, close the file and return -1
3. Otherwise, create and open the file data.txt. Copy all data from journal.txt to data.txt.
4. Return 0 if checkpointing completes.

Hints:
- The method open(...) will open a file and return a file descriptor.
- When creating a file, you will need to pass permissions as the third argument (i.e. 0600)
- The method lseek(...) can be used to seek to x bytes before the file with lseek(fd, -x, SEEK END)
- The method lseek(...) can also seek to the beginning of the file with SEEK SET
- After writing the the file, be sure to call fsync() to force write to disk
- Make sure to close any open file descriptors before returning from the method.
