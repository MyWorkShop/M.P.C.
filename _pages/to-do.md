---
ID: 46
post_title: TO DO
author: H_T
post_date: 2016-02-19 19:14:48
post_excerpt: ""
layout: page
permalink: http://www.mws.site/to-do/
published: true
---
<div class="para">
<h3><span id="Typical_BASIC_keywords" class="mw-headline">Typical BASIC keywords</span><span class="mw-editsection"><span class="mw-editsection-bracket">[</span><a title="Edit section: Typical BASIC keywords" href="https://en.wikipedia.org/w/index.php?title=BASIC&amp;action=edit&amp;section=13">edit</a><span class="mw-editsection-bracket">]</span></span></h3>
<dl><dt>Data manipulation</dt></dl>
<ul>
	<li>LET: assigns a value (which may be the result of an <a class="mw-redirect" title="Expression (programming)" href="https://en.wikipedia.org/wiki/Expression_(programming)">expression</a>) to a variable.</li>
	<li>DATA: holds a list of values which are assigned sequentially using the READ command.</li>
</ul>
<dl><dt>Program flow control</dt></dl>
<ul>
	<li>IF ... THEN ... ELSE: used to perform comparisons or make decisions.</li>
	<li>FOR ... TO ... {STEP} ... NEXT: repeat a section of code a given number of times. A variable that acts as a counter is available within the <a title="Control flow" href="https://en.wikipedia.org/wiki/Control_flow#Loops">loop</a>.</li>
	<li>WHILE ... WEND and REPEAT ... UNTIL: repeat a section of code while the specified condition is true. The condition may be evaluated before each iteration of the loop, or after.</li>
	<li>DO ... LOOP {WHILE} or {UNTIL}: repeat a section of code Forever or While/Until the specified condition is true. The condition may be evaluated before each iteration of the loop, or after.</li>
	<li><a class="mw-redirect" title="GOTO" href="https://en.wikipedia.org/wiki/GOTO">GOTO</a>: jumps to a numbered or labelled line in the program.</li>
	<li>GOSUB: jumps to a numbered or labelled line, executes the code it finds there until it reaches a RETURN Command, on which it jumps back to the operator following the GOSUB - either after a colon, or on the next line. This is used to implement <a title="Subroutine" href="https://en.wikipedia.org/wiki/Subroutine">subroutines</a>.</li>
	<li>ON ... GOTO/GOSUB: chooses where to jump based on the specified conditions. See <a title="Switch statement" href="https://en.wikipedia.org/wiki/Switch_statement">Switch statement</a> for other forms.</li>
	<li>DEF FN: a pair of keywords introduced in the early 1960s to define functions. The original BASIC functions were modelled on FORTRAN single-line functions. BASIC functions were one expression with variable arguments, rather than <a title="Subroutine" href="https://en.wikipedia.org/wiki/Subroutine">subroutines</a>, with a syntax on the model of <code>DEF FND(x) = x*x</code> at the beginning of a program. Function names were originally restricted to FN+one letter.</li>
</ul>
<dl><dt>Input and output</dt></dl>
<ul>
	<li>PRINT: displays a message on the screen or other output device.</li>
	<li>INPUT: asks the user to enter the value of a variable. The statement may include a prompt message.</li>
	<li>TAB or AT: sets the position where the next character will be shown on the screen or printed on paper.</li>
</ul>
<dl><dt>Miscellaneous</dt></dl>
<ul>
	<li>REM: holds a programmer's comment or REMark; often used to give a title to the program and to help identify the purpose of a given section of code.</li>
	<li>USR: transfers program control to a <a class="mw-redirect" title="Machine language" href="https://en.wikipedia.org/wiki/Machine_language">machine language</a> subroutine, usually entered as an alphanumeric <a title="String (computer science)" href="https://en.wikipedia.org/wiki/String_(computer_science)">string</a> or in a list of DATA statements.</li>
	<li>TRON: turns on a visual, screen representation of the flow of BASIC commands by displaying the number of each command line as it is run. The <a title="TRON command" href="https://en.wikipedia.org/wiki/TRON_command">TRON command</a>, largely obsolete now, stood for, TRace ON. This meant that command line numbers were displayed as the program ran, so that the command lines could be traced. This command allowed easier <a title="Debugging" href="https://en.wikipedia.org/wiki/Debugging">debugging</a> or correcting of command lines that caused problems in a program. Problems included a program terminating without providing a desired result, a program providing an obviously erroneous result, a program running in a non-terminating loop, or a program otherwise having a non-obvious error.</li>
	<li>TROFF: turns off the display of the number of each command line as command lines run after the command TRON has been used.</li>
</ul>
<h3><span id="Data_types_and_variables" class="mw-headline">Data types and variables</span><span class="mw-editsection"><span class="mw-editsection-bracket">[</span><a title="Edit section: Data types and variables" href="https://en.wikipedia.org/w/index.php?title=BASIC&amp;action=edit&amp;section=14">edit</a><span class="mw-editsection-bracket">]</span></span></h3>
Minimal versions of BASIC had only integer variables and one- or two-letter variable names, which minimised requirements of limited and expensive memory (RAM). More powerful versions had floating-point arithmetic, and variables could be labelled with names six or more characters long. There were some problems and restrictions in early implementations; for example, Applesoft allowed variable names to be several characters long, but only the first two were significant, thus it was possible to inadvertently write a program with variables "LOSS" and "LOAN", which would be treated as being the same; assigning a value to "LOAN" would silently overwrite the value intended as "LOSS". Keywords could not be used in variables in many early BASICs; "SCORE" would be interpreted as "SC" OR "E", where OR was a keyword.

<a title="String (computer science)" href="https://en.wikipedia.org/wiki/String_(computer_science)">String</a> variables are usually distinguished in many microcomputer dialects by having $ suffixed to their name, and values are often identified as strings by being delimited by "double quotation marks".

Arrays in BASIC could contain integers, floating point or string variables.

Some dialects of BASIC supported <a title="Matrix (mathematics)" href="https://en.wikipedia.org/wiki/Matrix_(mathematics)">matrices and matrix operations</a>, useful for the solution of sets of simultaneous linear algebraic equations. These dialects would directly support matrix operations such as assignment, addition, multiplication (of compatible matrix types), and evaluation of a determinant. Many microcomputer BASICs did not support this data type; matrix operations were still possible, but had to be programmed explicitly on array elements.
<h3><span id="Examples" class="mw-headline">Examples</span><span class="mw-editsection"><span class="mw-editsection-bracket">[</span><a title="Edit section: Examples" href="https://en.wikipedia.org/w/index.php?title=BASIC&amp;action=edit&amp;section=15">edit</a><span class="mw-editsection-bracket">]</span></span></h3>
<h4><span id="Unstructured_BASIC" class="mw-headline">Unstructured BASIC</span><span class="mw-editsection"><span class="mw-editsection-bracket">[</span><a title="Edit section: Unstructured BASIC" href="https://en.wikipedia.org/w/index.php?title=BASIC&amp;action=edit&amp;section=16">edit</a><span class="mw-editsection-bracket">]</span></span></h4>
The original Dartmouth Basic was unusual in having a matrix keyword, MAT.<sup id="cite_ref-26" class="reference"><a href="https://en.wikipedia.org/wiki/BASIC#cite_note-26">[notes 2]</a></sup> Although dropped by most later microprocessor derivatives it is used in this example from the 1968 manual<sup id="cite_ref-27" class="reference"><a href="https://en.wikipedia.org/wiki/BASIC#cite_note-27">[25]</a></sup> which averages the numbers that are input:
<div class="mw-highlight mw-content-ltr" dir="ltr">
<pre><span class="nl">5</span> <span class="kd">LET</span> <span class="vg">S</span> <span class="o">=</span> <span class="il">0</span> 
<span class="nl">10</span> <span class="vg">MAT</span> <span class="kr">INPUT</span> <span class="vg">V</span> 
<span class="nl">20</span> <span class="kd">LET</span> <span class="vg">N</span> <span class="o">=</span> <span class="vg">NUM</span> 
<span class="nl">30</span> <span class="kr">IF</span> <span class="vg">N</span> <span class="o">=</span> <span class="il">0</span> <span class="kr">THEN</span> <span class="il">99</span> 
<span class="nl">40</span> <span class="kr">FOR</span> <span class="vg">I</span> <span class="o">=</span> <span class="il">1</span> <span class="k">TO</span> <span class="vg">N</span> 
<span class="nl">45</span> <span class="kd">LET</span> <span class="vg">S</span> <span class="o">=</span> <span class="vg">S</span> <span class="o">+</span> <span class="vg">V</span><span class="p">(</span><span class="vg">I</span><span class="p">)</span> 
<span class="nl">50</span> <span class="kr">NEXT</span> <span class="vg">I</span> 
<span class="nl">60</span> <span class="kr">PRINT</span> <span class="vg">S</span><span class="o">/</span><span class="vg">N</span> 
<span class="nl">70</span> <span class="vg">GO</span> <span class="k">TO</span> <span class="il">5</span> 
<span class="nl">99</span> <span class="kr">END</span>
</pre>
</div>
New BASIC programmers on a home computer might start with a simple program, perhaps using the language's PRINT statement to display a message on the screen; a well-known and often-replicated example is <a title="The C Programming Language" href="https://en.wikipedia.org/wiki/The_C_Programming_Language">Kernighan and Ritchie</a>'s <a class="mw-redirect" title="Hello world program" href="https://en.wikipedia.org/wiki/Hello_world_program">Hello world program</a>:
<div class="mw-highlight mw-content-ltr" dir="ltr">
<pre><span class="nl">10</span> <span class="kr">PRINT</span> <span class="s2">"Hello, World!"</span>
<span class="nl">140</span> <span class="kr">END</span>
</pre>
</div>
An <a title="Infinite loop" href="https://en.wikipedia.org/wiki/Infinite_loop">infinite loop</a> could be used to fill the display with the message.

Most first-generation BASIC versions such as <a title="MSX BASIC" href="https://en.wikipedia.org/wiki/MSX_BASIC">MSX BASIC</a> and <a title="GW-BASIC" href="https://en.wikipedia.org/wiki/GW-BASIC">GW-BASIC</a> supported simple data types, loop cycles and arrays. The following example is written for GW-BASIC, but will work in most versions of BASIC with minimal changes:
<div class="mw-highlight mw-content-ltr" dir="ltr">
<pre><span class="nl">10</span> <span class="kr">INPUT</span> <span class="s2">"What is your name: "</span><span class="p">,</span> <span class="vg">U$</span>
<span class="nl">20</span> <span class="kr">PRINT</span> <span class="s2">"Hello "</span><span class="p">;</span> <span class="vg">U$</span>
<span class="nl">30</span> <span class="kr">INPUT</span> <span class="s2">"How many stars do you want: "</span><span class="p">,</span> <span class="vg">N</span>
<span class="nl">40</span> <span class="vg">S$</span> <span class="o">=</span> <span class="s2">""</span>
<span class="nl">50</span> <span class="kr">FOR</span> <span class="vg">I</span> <span class="o">=</span> <span class="il">1</span> <span class="k">TO</span> <span class="vg">N</span>
<span class="nl">60</span> <span class="vg">S$</span> <span class="o">=</span> <span class="vg">S$</span> <span class="o">+</span> <span class="s2">"*"</span>
<span class="nl">70</span> <span class="kr">NEXT</span> <span class="vg">I</span>
<span class="nl">80</span> <span class="kr">PRINT</span> <span class="vg">S$</span>
<span class="nl">90</span> <span class="kr">INPUT</span> <span class="s2">"Do you want more stars? "</span><span class="p">,</span> <span class="vg">A$</span>
<span class="nl">100</span> <span class="kr">IF</span> <span class="kr">LEN</span><span class="p">(</span><span class="vg">A$</span><span class="p">)</span> <span class="o">=</span> <span class="il">0</span> <span class="kr">THEN</span> <span class="kr">GOTO</span> <span class="nl">90</span>
<span class="nl">110</span> <span class="vg">A$</span> <span class="o">=</span> <span class="kr">LEFT$</span><span class="p">(</span><span class="vg">A$</span><span class="p">,</span> <span class="il">1</span><span class="p">)</span>
<span class="nl">120</span> <span class="kr">IF</span> <span class="vg">A$</span> <span class="o">=</span> <span class="s2">"Y"</span> <span class="ow">OR</span> <span class="vg">A$</span> <span class="o">=</span> <span class="s2">"y"</span> <span class="kr">THEN</span> <span class="kr">GOTO</span> <span class="nl">30</span>
<span class="nl">130</span> <span class="kr">PRINT</span> <span class="s2">"Goodbye "</span><span class="p">;</span> <span class="vg">U$</span>
<span class="nl">140</span> <span class="kr">END</span>
</pre>
</div>
The resulting dialog might resemble:
<pre>What is your name: Mike
Hello Mike
How many stars do you want: 7
*******
Do you want more stars? yes
How many stars do you want: 3
***
Do you want more stars? no
Goodbye Mike
</pre>
<h4><span id="Structured_BASIC" class="mw-headline">Structured BASIC</span><span class="mw-editsection"><span class="mw-editsection-bracket">[</span><a title="Edit section: Structured BASIC" href="https://en.wikipedia.org/w/index.php?title=BASIC&amp;action=edit&amp;section=17">edit</a><span class="mw-editsection-bracket">]</span></span></h4>
Second-generation BASICs (for example, <a title="HP BASIC for OpenVMS" href="https://en.wikipedia.org/wiki/HP_BASIC_for_OpenVMS">VAX Basic</a>, <a title="SuperBASIC" href="https://en.wikipedia.org/wiki/SuperBASIC">SuperBASIC</a>, <a title="True BASIC" href="https://en.wikipedia.org/wiki/True_BASIC">True BASIC</a>, <a title="QuickBASIC" href="https://en.wikipedia.org/wiki/QuickBASIC">QuickBASIC</a>, <a title="BBC BASIC" href="https://en.wikipedia.org/wiki/BBC_BASIC">BBC BASIC</a> and <a title="PowerBASIC" href="https://en.wikipedia.org/wiki/PowerBASIC">PowerBASIC</a>) introduced a number of features into the language, primarily related to structured and procedure-oriented programming. Usually, <a title="Line number" href="https://en.wikipedia.org/wiki/Line_number">line numbering</a> is omitted from the language and replaced with <a title="Label (computer science)" href="https://en.wikipedia.org/wiki/Label_(computer_science)">labels</a> (for<a class="mw-redirect" title="GOTO" href="https://en.wikipedia.org/wiki/GOTO">GOTO</a>) and <a title="Subroutine" href="https://en.wikipedia.org/wiki/Subroutine">procedures</a> to encourage easier and more flexible design.<sup id="cite_ref-GBvsQB_28-0" class="reference"><a href="https://en.wikipedia.org/wiki/BASIC#cite_note-GBvsQB-28">[26]</a></sup> In addition keywords and structures to support repetition, selection and procedures with local variables were introduced.

The following example is in QuickBASIC:
<div class="mw-highlight mw-content-ltr" dir="ltr">
<pre><span class="kd">DECLARE</span> <span class="nv">SUB</span> <span class="n">PrintSomeStars</span> <span class="p">(</span><span class="vg">StarCount!</span><span class="p">)</span>
<span class="c1">REM QuickBASIC example</span>
<span class="kr">INPUT</span> <span class="s2">"What is your name: "</span><span class="p">,</span> <span class="vg">UserName$</span>
<span class="kr">PRINT</span> <span class="s2">"Hello "</span><span class="p">;</span> <span class="vg">UserName$</span>
<span class="kr">DO</span>
   <span class="kr">INPUT</span> <span class="s2">"How many stars do you want: "</span><span class="p">,</span> <span class="vg">NumStars</span>
   <span class="kr">CALL</span> <span class="vg">PrintSomeStars</span><span class="p">(</span><span class="vg">NumStars</span><span class="p">)</span>
   <span class="kr">DO</span>
      <span class="kr">INPUT</span> <span class="s2">"Do you want more stars? "</span><span class="p">,</span> <span class="vg">Answer$</span>
   <span class="kr">LOOP</span> <span class="k">UNTIL</span> <span class="vg">Answer$</span> <span class="o">&lt;&gt;</span> <span class="s2">""</span>
   <span class="vg">Answer$</span> <span class="o">=</span> <span class="kr">LEFT$</span><span class="p">(</span><span class="vg">Answer$</span><span class="p">,</span> <span class="il">1</span><span class="p">)</span>
<span class="kr">LOOP</span> <span class="kr">WHILE</span> <span class="kr">UCASE$</span><span class="p">(</span><span class="vg">Answer$</span><span class="p">)</span> <span class="o">=</span> <span class="s2">"Y"</span>
<span class="kr">PRINT</span> <span class="s2">"Goodbye "</span><span class="p">;</span> <span class="vg">UserName$</span>
<span class="kr">END</span>

<span class="kr">SUB</span> <span class="vg">PrintSomeStars</span> <span class="p">(</span><span class="vg">StarCount</span><span class="p">)</span>
   <span class="kr">REM</span> <span class="vg">This</span> <span class="vg">procedure</span> <span class="vg">uses</span> <span class="vg">a</span> <span class="vg">local</span> <span class="vg">variable</span> <span class="vg">called</span> <span class="vg">Stars$</span>
   <span class="vg">Stars$</span> <span class="o">=</span> <span class="kr">STRING$</span><span class="p">(</span><span class="vg">StarCount</span><span class="p">,</span> <span class="s2">"*"</span><span class="p">)</span>
   <span class="kr">PRINT</span> <span class="vg">Stars$</span>
<span class="kr">END</span> <span class="kr">SUB</span>
</pre>
</div>
<h4><span id="BASIC_with_object-oriented_features" class="mw-headline">BASIC with object-oriented features</span><span class="mw-editsection"><span class="mw-editsection-bracket">[</span><a title="Edit section: BASIC with object-oriented features" href="https://en.wikipedia.org/w/index.php?title=BASIC&amp;action=edit&amp;section=18">edit</a><span class="mw-editsection-bracket">]</span></span></h4>
Third-generation BASIC dialects such as <a title="Visual Basic" href="https://en.wikipedia.org/wiki/Visual_Basic">Visual Basic</a>, <a title="Xojo" href="https://en.wikipedia.org/wiki/Xojo">Xojo</a>, <a class="mw-redirect" title="StarOffice Basic" href="https://en.wikipedia.org/wiki/StarOffice_Basic">StarOffice Basic</a> and <a class="mw-redirect" title="BlitzMax" href="https://en.wikipedia.org/wiki/BlitzMax">BlitzMax</a> introduced features to support object-oriented and <a title="Event-driven programming" href="https://en.wikipedia.org/wiki/Event-driven_programming">event-driven programming</a> paradigm. Most built-in procedures and functions are now represented as <i>methods</i> of standard objects rather than <i>operators</i>. Also, the <a class="mw-redirect" title="Operating System" href="https://en.wikipedia.org/wiki/Operating_System">Operating System</a> became more and more available to the BASIC language.

The following example is in <a title="Visual Basic .NET" href="https://en.wikipedia.org/wiki/Visual_Basic_.NET">Visual Basic .NET</a>:
<div class="mw-highlight mw-content-ltr" dir="ltr">
<pre><span class="k">Public</span> <span class="k">Class</span> <span class="nc">StarsProgram</span>
   <span class="k">Public</span> <span class="k">Shared</span> <span class="k">Sub</span> <span class="nf">Main</span><span class="p">()</span>
      <span class="k">Dim</span> <span class="n">UserName</span><span class="p">,</span> <span class="n">Answer</span><span class="p">,</span> <span class="n">stars</span> <span class="ow">As</span> <span class="kt">String</span><span class="p">,</span> <span class="n">NumStars</span> <span class="ow">As</span> <span class="kt">Integer</span>
      <span class="n">Console</span><span class="p">.</span><span class="n">Write</span><span class="p">(</span><span class="s">"What is your name: "</span><span class="p">)</span>
      <span class="n">UserName</span> <span class="o">=</span> <span class="n">Console</span><span class="p">.</span><span class="n">ReadLine</span><span class="p">()</span>
      <span class="n">Console</span><span class="p">.</span><span class="n">WriteLine</span><span class="p">(</span><span class="s">"Hello {0}"</span><span class="p">,</span> <span class="n">UserName</span><span class="p">)</span>
      <span class="k">Do</span>
         <span class="n">Console</span><span class="p">.</span><span class="n">Write</span><span class="p">(</span><span class="s">"How many stars do you want: "</span><span class="p">)</span>
         <span class="n">NumStars</span> <span class="o">=</span> <span class="k">CInt</span><span class="p">(</span><span class="n">Console</span><span class="p">.</span><span class="n">ReadLine</span><span class="p">())</span>
         <span class="n">stars</span> <span class="o">=</span> <span class="k">New</span> <span class="kt">String</span><span class="p">(</span><span class="s">"*"</span><span class="p">,</span> <span class="n">NumStars</span><span class="p">)</span>
         <span class="n">Console</span><span class="p">.</span><span class="n">WriteLine</span><span class="p">(</span><span class="n">stars</span><span class="p">)</span>
         <span class="k">Do</span>
            <span class="n">Console</span><span class="p">.</span><span class="n">Write</span><span class="p">(</span><span class="s">"Do you want more stars? "</span><span class="p">)</span>
            <span class="n">Answer</span> <span class="o">=</span> <span class="n">Console</span><span class="p">.</span><span class="n">ReadLine</span><span class="p">()</span>
         <span class="k">Loop</span> <span class="n">Until</span> <span class="n">Answer</span> <span class="o">&lt;&gt;</span> <span class="s">""</span>
         <span class="n">Answer</span> <span class="o">=</span> <span class="n">Answer</span><span class="p">.</span><span class="n">Substring</span><span class="p">(</span><span class="mi">0</span><span class="p">,</span> <span class="mi">1</span><span class="p">)</span>
      <span class="k">Loop</span> <span class="k">While</span> <span class="n">Answer</span><span class="p">.</span><span class="n">ToUpper</span><span class="p">()</span> <span class="o">=</span> <span class="s">"Y"</span>
      <span class="n">Console</span><span class="p">.</span><span class="n">WriteLine</span><span class="p">(</span><span class="s">"Goodbye {0}"</span><span class="p">,</span> <span class="n">UserName</span><span class="p">)</span>
   <span class="k">End</span> <span class="k">Sub</span>
<span class="k">End</span> <span class="k">Class</span></pre>
</div>
</div>