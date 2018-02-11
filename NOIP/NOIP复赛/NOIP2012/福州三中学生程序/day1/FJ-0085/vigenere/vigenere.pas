const  	a=ord('a');
	aa=ord('A');
	ff='vigenere';
var 	s:ansistring;
	k:array[0..110]of longint;
	i,j,x,n,m:longint;
function work(x:longint):longint;
begin
if (x>=k[j])then exit(x-k[j])
else exit(x-k[j]+26);
end;

begin
assign(input,ff+'.in');reset(input);
assign(output,ff+'.out');rewrite(output);
readln(s);n:=length(s);
for i:=1 to n do begin
	x:=ord(s[i])-a;
        if (x>=0)and(x<26)then k[i]:=x
        else k[i]:=ord(s[i])-aa;
        end;
readln(s);
j:=0;m:=length(s);
for i:=1 to m do begin
	j:=j+1;
        if j>n then j:=1;
	x:=ord(s[i])-a;
	if (x>=0)and(x<26)then x:=work(x)+a
        else x:=work(ord(s[i])-aa)+aa;
	write(char(x));
        end;
writeln;
close(input);close(output);
end.
