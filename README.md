 
Secrets of “printf”
Professor Don Colton
Brigham Young University Hawaii
printf
 is the C language function to do format-ted printing. The same function is also available inPERL. This paper explains how
 printf
 works, andhow to design the proper formatting speciﬁcation forany occasion.
1 Background
In the early days, computer programmers wouldwrite their own subroutines to read in and print outnumbers. It is not terribly diﬃcult, actually. Justallocate a character array to hold the result, dividethe number by ten, keep the remainder, add x30 toit, and store it at the end of the array. Repeat theprocess until all the digits are found. Then print it.Too easy, right?But even though it was easy (for Einstein), it stilltook some eﬀort. And what about error checking,and negative numbers? So the computer program-mers brought forth libraries of prerecorded func-tions. And it was good. Eventually the most popularof these functions were canonized into membershipin the “standard” libraries. Number printing waspopular enough to gain this hallowed honor.This meant that programmers did not have toreinvent the number-printing subroutine again andagain. It also meant that everybody’s favorite op-tions tried to make it into the standard.Thus was
 printf
 born.
2 Simple Printing
In the most simple case,
 printf
 takes one argument:a string of characters to be printed. This string iscomposed of characters, each of which is printed ex-actly as it appears. So
 printf("xyz");
 would sim-ply print an x, then a y, and ﬁnally a z. This is notexactly “formatted” printing, but it is still the basisof what
 printf
 does.
2.1 Naturally Special Characters
To identify the start of the string, we put a double-quote (
"
) at the front. To identify the end of thestring we put another double-quote at the end. Butwhat if we want to actually print a double-quote?We can’t exactly put a double-quote in the middleof the string because it would be mistaken for theend-of-string marker. Double-quote is a special char-acter. The normal print-what-you-see rules do notapply.Diﬀerent languages take diﬀerent approaches tothis problem. Some require the special character tobe entered twice. C uses backslash (virgule,
 \
) asan escape character to change the meaning of thenext character after it. Thus, to print a double-quote you type in backslash double-quote. To printa backslash, you must escape it by typing anotherbackslash in front of it. The ﬁrst backslash means“give the next character its alternate meaning.” Thesecond backslash has an alternate meaning of “printa backslash.”Without a backslash, special characters have anatural special meaning. With a backslash theyprint as they appear. Here is a partial list.
\
 escape the next character
\\
 print a backslash
"
 start or end of string
\"
 print a double quote
’
 start or end a character constant
\’
 print a single quote
%
 start a format speciﬁcation
\%
 print a percent sign
2.2 Alternately Special Characters
On the other hand we have characters that normallyprint as you would expect, but when you add a back-slash, then they become special. An example is thenewline character. To print an
 n
, we simply type inan
 n
. To print a newline, we type in a
 \n
, thus