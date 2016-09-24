<%-- 
    Document   : FAQs
    Created on : 2011-11-20, 21:13:45
    Author     : pz
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>

<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
        <link rel="stylesheet" type="text/css" href="Css/layout.css" />

    </head>
    <body>
        <jsp:include page="head.jsp" flush="true" />
        <jsp:include page="FLeft.jsp" flush="true" />
        <div id="content">
        <h1 id="title" style="text-align: center;">Frequently Asked Questions</h1>
            <hr />
            <p class="MsoNormal"><span lang="EN-US" style="font-size: 12.0pt; color: green">
Q</span><span lang="EN-US" style="font-size: 12.0pt">: Where are the input and 
the output?</span></p>
<p class="MsoNormal"><span lang="EN-US" style="font-size: 12.0pt; color: red">A</span><span lang="EN-US" style="font-size: 12.0pt">: 
Your program shall always read input from stdin (Standard Input) and write 
output to stdout (Standard Output). For example, you can use 'scanf' in C or 'cin' 
in C++ to read from stdin, and use 'printf' in C or 'cout' in C++ to write to 
stdout.</span></p>
<p class="MsoNormal"><span lang="EN-US" style="font-size: 12.0pt">User programs 
are not allowed to open and read from/write to files. You will get a ‘<span style="color: green">Runtime 
Error</span>’ or a ‘<span style="color: green">Wrong Answer</span>’ if you try 
to do so. </span></p>
<p class="MsoNormal">　</p>
<p class="MsoNormal"><span lang="EN-US" style="font-size: 12.0pt">Here is a 
sample solution for problem 1000 using C++/G++:</span></p>
<p class="MsoNormal">
<span lang="EN-US" style="font-size: 12.0pt; color: #20B000">#include &lt;iostream&gt;</span></p>
<p class="MsoNormal">
<span lang="EN-US" style="font-size: 12.0pt; color: #20B000">&nbsp;</span><span style="font-size: 12.0pt; color: #20B000">using 
namespace std;</span></p>
<p class="MsoNormal">
<font size="3" color="#20B000">int </font>
<span lang="EN-US" style="font-size: 12.0pt; color: #20B000"> &nbsp;main()</span></p>
<p class="MsoNormal">
<span lang="EN-US" style="font-size: 12.0pt; color: #20B000">{</span></p>
<p class="MsoNormal">
<span lang="EN-US" style="font-size: 12.0pt; color: #20B000">&nbsp;&nbsp;&nbsp; int a,b;</span></p>
<p class="MsoNormal">
<span lang="EN-US" style="font-size: 12.0pt; color: #20B000">&nbsp;&nbsp;&nbsp; cin &gt;&gt; a &gt;&gt; b;</span></p>
<p class="MsoNormal">
<span lang="EN-US" style="font-size: 12.0pt; color: #20B000">&nbsp;&nbsp;&nbsp; cout &lt;&lt; a+b &lt;&lt; 
endl;</span></p>
<p class="MsoNormal">
<span lang="en-us"><font size="3" color="#20B000">&nbsp;&nbsp;&nbsp; return 0;</font></span></p>
<p class="MsoNormal">
<span lang="EN-US" style="font-size: 12.0pt; color: #20B000">}</span></p>
<p class="MsoNormal"><font color="#FF0000" size="5">It's important that the 
return type of main() must be int when you use G++/GCC,or you may get </font>
<font size="5" color="#008080">compile error</font><font color="#FF0000" size="5">.</font></p>
<p class="MsoNormal"><span lang="EN-US" style="font-size: 12.0pt">Here is a 
sample solution for problem 1000 using C/GCC:</span></p>
<p class="MsoNormal">
<span lang="EN-US" style="font-size: 12.0pt; color: #20B000">#include &lt;stdio.h&gt;</span></p>
<p class="MsoNormal">
<span lang="EN-US" style="font-size: 12.0pt; color: #20B000">&nbsp;</span><span style="font-size: 12.0pt; color: #20B000">int </span>
<span lang="EN-US" style="font-size: 12.0pt; color: #20B000">main()</span></p>
<p class="MsoNormal">
<span lang="EN-US" style="font-size: 12.0pt; color: #20B000">{</span></p>
<p class="MsoNormal">
<span lang="EN-US" style="font-size: 12.0pt; color: #20B000">&nbsp;&nbsp;&nbsp; int a,b;</span></p>
<p class="MsoNormal">
<span lang="EN-US" style="font-size: 12.0pt; color: #20B000">&nbsp;&nbsp;&nbsp; scanf(&quot;%d 
%d&quot;,&amp;a, &amp;b);</span></p>
<p class="MsoNormal">
<span lang="EN-US" style="font-size: 12.0pt; color: #20B000">&nbsp;&nbsp;&nbsp; printf(&quot;%d\n&quot;,a+b);</span></p>
<p class="MsoNormal">
<span lang="en-us"><font size="3" color="#20B000">&nbsp;&nbsp;&nbsp; return 0;</font></span></p>
<p class="MsoNormal">
<span lang="EN-US" style="font-size: 12.0pt; color: #20B000">}</span></p>
<p class="MsoNormal"><span lang="EN-US" style="font-size: 12.0pt">&nbsp;</span></p>
<p class="MsoNormal"><span lang="EN-US" style="font-size: 12.0pt">Here is a 
sample solution for problem 1000 using PASCAL:</span></p>
<p class="MsoNormal">
<span lang="EN-US" style="font-size: 12.0pt; color: #20B000">program 
p1000(Input,Output); </span></p>
<p class="MsoNormal">
<span lang="EN-US" style="font-size: 12.0pt; color: #20B000">var </span></p>
<p class="MsoNormal">
<span lang="EN-US" style="font-size: 12.0pt; color: #20B000">&nbsp; a,b:Integer;
</span></p>
<p class="MsoNormal">
<span lang="EN-US" style="font-size: 12.0pt; color: #20B000">begin </span></p>
<p class="MsoNormal">
<span lang="EN-US" style="font-size: 12.0pt; color: #20B000">&nbsp;&nbsp; Readln(a,b);
</span></p>
<p class="MsoNormal">
<span lang="EN-US" style="font-size: 12.0pt; color: #20B000">&nbsp;&nbsp; Writeln(a+b);
</span></p>
<p class="MsoNormal">
<span lang="EN-US" style="font-size: 12.0pt; color: #20B000">end.</span></p>
<p class="MsoNormal">
　</p>
<p class="MsoNormal">
<span lang="EN-US" style="font-size: 12.0pt">Here is a 
sample solution for problem 1000 using  </span><span style="font-size: 12.0pt">
JAVA</span><span lang="EN-US" style="font-size: 12.0pt">:</span></p>
<p class="MsoNormal">
<font color="#FF0000" size="5">Now java compiler is jdk 1.5, next is program for 
1000</font></p>
<p class="MsoNormal">
<font color="#20B000">import java.io.*;<br>
import java.util.*;<br>
public class Main<br>
{<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; public static 
void main(String args[]) throws Exception<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; {<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 
Scanner cin=new Scanner(System.in);<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 
int a=cin.nextInt(),b=cin.nextInt();<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 
System.out.println(a+b);<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; }<br>
}</font></p>
<p class="MsoNormal">
　</p>
<p class="MsoNormal">
　</p>
<p class="MsoNormal">
<font color="#FF0000">Old program for jdk 1.4</font></p>
<p class="MsoNormal">
　</p>
<p class="MsoNormal"><font color="#20B000">import java.io.*;<br>
import java.util.*;<br>
<br>
public class Main<br>
{<br>
&nbsp;&nbsp;&nbsp; public static void main (String args[]) throws Exception<br>
&nbsp;&nbsp;&nbsp; {<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; BufferedReader stdin = <br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; new 
BufferedReader(<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 
new InputStreamReader(System.in));<br>
<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; String line = stdin.readLine();<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; StringTokenizer st = new 
StringTokenizer(line);<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; int a = Integer.parseInt(st.nextToken());<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; int b = Integer.parseInt(st.nextToken());<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; System.out.println(a+b);<br>
&nbsp;&nbsp;&nbsp; }<br>
}</font></p>
<p class="MsoNormal">　</p>
<p class="MsoNormal"><span lang="EN-US" style="font-size: 12.0pt; color: green">
Q</span><span lang="EN-US" style="font-size: 12.0pt">:  </span>
<span style="font-size: 12.0pt">How to submit java program</span><span lang="EN-US" style="font-size: 12.0pt">?</span></p>
<p class="MsoNormal"><span lang="EN-US" style="font-size: 12.0pt; color: red">A</span><span lang="EN-US" style="font-size: 12.0pt">: 
The Java programs submitted must be in a single source code (not .class) file.&nbsp; 
They must read and write the standard input/output, as the other lang</span><span style="font-size: 12.0pt">uages</span><span lang="EN-US" style="font-size: 12.0pt">. 
All programs must begin in a static main method in a Main class.&nbsp; However, 
you can add and instance as many classes as needed. <br>
　</span></p>
<p class="MsoNormal"><span lang="EN-US" style="font-size: 12.0pt; color: green">
Q</span><span lang="EN-US" style="font-size: 12.0pt">: </span><font size="3">Can 
I use shortcut key when submitting?</font></p>
<p class="MsoNormal"><span lang="EN-US" style="font-size: 12.0pt; color: red">A</span><span lang="EN-US" style="font-size: 12.0pt">: </span>
<span style="font-size: 12.0pt">Here are shortcut keys defined in the submit 
page</span></p>
<p class="MsoNormal"><font size="3"><font color="#FF00FF"><b>ALT+s</b> </font>&nbsp;&nbsp; 
:Submit button</font></p>
<p class="MsoNormal"><font size="3"><font color="#FF00FF"><b>ALT+u&nbsp; </b>
</font>&nbsp; :User id field , if you haven't login.</font></p>
<p class="MsoNormal"><font size="3"><b><font color="#FF00FF">ALT+l </font>&nbsp;</b>&nbsp; 
:Language Option</font></p>
<p class="MsoNormal"><font size="3"><b><font color="#FF00FF">ALT+p </font>&nbsp;</b>&nbsp; 
:Problem Id filed</font></p>
<p class="MsoNormal">　</p>
<p class="MsoNormal">　</p>
<p class="MsoNormal"><span lang="EN-US" style="font-size: 12.0pt; color: green">
Q</span><span lang="EN-US" style="font-size: 12.0pt">: What is the meaning of 
the judge's replies?</span></p>
<p class="MsoNormal"><span lang="EN-US" style="font-size: 12.0pt; color: red">A</span><span lang="EN-US" style="font-size: 12.0pt">: 
Here is a list of the judge's replies and their meaning:</span></p>
<p class="MsoNormal"><span lang="EN-US" style="font-size: 12.0pt; color: blue">
Accepted</span><span lang="EN-US" style="font-size: 12.0pt">: OK! Your program 
is correct!</span></p>
<p class="MsoNormal"><span lang="EN-US" style="font-size: 12.0pt; color: blue">
Presentation Error</span><span lang="EN-US" style="font-size: 12.0pt">: Your 
output format is not exactly the same as the judge's output, although your 
answer to the problem is correct. Check your output for spaces, blank lines, etc 
against the problem output specification.</span></p>
<p class="MsoNormal"><span lang="EN-US" style="font-size: 12.0pt; color: blue">
Wrong Answer</span><span lang="EN-US" style="font-size: 12.0pt">: Correct 
solution not reached for the inputs. The inputs and outputs that we use to test 
the programs are not public (it is recommendable to get accustomed to a true 
contest dynamic ;-).</span></p>
<p class="MsoNormal"><span lang="EN-US" style="font-size: 12.0pt; color: blue">
Runtime Error</span><span lang="EN-US" style="font-size: 12.0pt">: Your program 
failed during the execution (</span><span lang="EN-US">illegal file access,
</span><span lang="EN-US" style="font-size: 12.0pt">stack overflow, pointer 
reference out of range, floating point exception, divided by zero...).</span></p>
<p class="MsoNormal"><span lang="EN-US" style="font-size: 12.0pt; color: blue">
Time Limit Exceeded</span><span lang="EN-US" style="font-size: 12.0pt">: Your 
program tried to run during too much time.</span></p>
<blockquote>
	<p class="MsoNormal"><span lang="en-us"><font size="3">Now each problem have 
	two time limit--TOTAL TIME LIMIT and CASE TIME LIMIT. When JudgeOnline run 
	your program ,it redirect your program's standard input to input file, then 
	you can just read from standard input. And one problem may have several 
	input files, when your program finished one input file and produce the 
	correct output,&nbsp; JudgeOnline then restart your program to deal with 
	next input file. Each input file's format is exactly as the problem's input 
	specification. Case time limit is the maximum time your program is allowed 
	to use for each input file, and TOTAL TIME LIMIT is the maximum time for you 
	to pass all input file. If your program exceed any one of this two time 
	limit, you will receive time limit exceed.</font></span></p>
	<p class="MsoNormal"><span lang="en-us"><font size="3">As most problems only 
	have one or two input file (of course, also one or two output file), then 
	the CASE TIME LIMIT is trivial then it will be set equal to TOTAL TIME LIMIT 
	and the problem description will not display CASE TIME LIMIT.</font></span></p>
	<p class="MsoNormal"><span lang="en-us"><font size="3">So when you got time 
	limit exceed, but you find the time your program used is much less than 
	TOTAL TIME LIMIT----your program must exceed CASE TIME LIMIT.</font></span></p>
</blockquote>
<p class="MsoNormal"><span lang="EN-US" style="font-size: 12.0pt; color: blue">
Memory Limit Exceeded</span><span lang="EN-US" style="font-size: 12.0pt">: Your 
program tried to use more memory than the judge default settings. </span></p>
<p class="MsoNormal"><span lang="EN-US" style="font-size: 12.0pt; color: blue">
Output Limit Exceeded</span><span lang="EN-US" style="font-size: 12.0pt">: Your 
program tried to write too much information. This usually occurs if it goes into 
a infinite loop. Currently the output limit is 2*answer file’s size.</span></p>
<p class="MsoNormal"><span lang="EN-US" style="font-size: 12.0pt; color: blue">
Compile Error</span><span lang="EN-US" style="font-size: 12.0pt">: The compiler 
could not compile your program. Of course, warning messages are not error 
messages. Click the link at the judge reply to see the actual error message.</span></p></div>
<jsp:include page="foot.jsp" flush="true" />
    </body>
</html>
