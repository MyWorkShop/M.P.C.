---
ID: 36
post_title: >
  Installation of Verilog development
  environment under Ubuntu
author: H_T
post_date: 2016-02-17 21:56:47
post_excerpt: ""
layout: post
permalink: >
  http://www.mws.site/installation-of-verilog-development-environment-under-ubuntu/
published: true
---
Under Ubuntu ,you can use iverilog to analog Verilog code.

To install it

<code>sudo apt-get update
sudo apt-get install verilog
</code>

So easy! Right?
Then you can create an new file named hello.v
<code>module main;
initial
begin
$display("Hello, World");
$finish ;
end
endmodule
</code>
Compile this program and show the result of it with the command:
<code>iverilog -o hello hello.v
vvp hello
</code>
Then you will get:
<code>Hello, World
</code>

Then you need to install GTKWave
<code>sudo apt-get install GTKWave</code>

You can create an new file named add.v
<code>module adder4(cout,sum,ina,inb,cin);
output[3:0] sum;
output cout;
input[3:0] ina,inb;
input cin;</code>

assign {cout,sum}=ina+inb+cin;
endmodule
And then create a testbeach named test_add.v
<code>`timescale 1ns/1ns
module test_adder4;</code>

//Declare variables
wire[3:0] sum;
wire cout;
reg[3:0] ina,inb;
reg cin;

//Instantiate the module adder4
adder4 adder4_1(cout,sum,ina,inb,cin);

//Stimulate the inputs, Finish the stimulation at 90 time units
initial
begin
#0 ina = 4'b0001; inb = 4'b1010; cin = 1'b0;
#5 ina = 4'b0010; inb = 4'b1010; cin = 1'b1;
#5 ina = 4'b0010; inb = 4'b1110; cin = 1'b0;
#5 ina = 4'b0011; inb = 4'b1100; cin = 1'b1;
#5 ina = 4'b0111; inb = 4'b1001; cin = 1'b0;
#5 ina = 4'b0001; inb = 4'b1100; cin = 1'b1;
#5 ina = 4'b0011; inb = 4'b1100; cin = 1'b0;
#5 ina = 4'b0111; inb = 4'b1111; cin = 1'b1;
#5 $finish;
end

initial
$monitor("At time %t, ina(%b) + inb(%b) + cin(%b) = sum(%b)(%2d),cout(%b)",$time, ina, inb, cin, sum, sum, cout);

initial
begin
$dumpfile("test.vcd");
$dumpvars(0,test_adder4);
end
endmodule
Compile this program and show the result of it with the command:
<code>iverilog -o test add.v test_add.v
vvp -n test -lxt2
cp test.vcd test.lxt
gtkwave test.lxt</code>

You will get:
<img class="alignleft wp-image-40 size-full" src="http://www.mws.site/wp-content/uploads/2016/02/2012041821191181.jpg" alt="2012041821191181" width="1201" height="366" />
<img class="alignleft wp-image-41 size-full" src="http://www.mws.site/wp-content/uploads/2016/02/2012041821193593.jpg" alt="2012041821193593" width="1206" height="150" />
The installation has finished,<strong>enjoy it</strong>!