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

<code>
sudo apt-get update
sudo apt-get install verilog
</code>

So easy,right?
Then you can create an new file named hello.v
<code>
module main;
initial
begin
$display("Hello, World");
$finish ;
end
endmodule
</code>
Compile this program and show the result of it with the command:
<code>
iverilog -o hello hello.v
vvp hello
</code>
Then you will get:
<code>
Hello, World
</code>
The installation has finished,<strong>enjoy it</strong>!