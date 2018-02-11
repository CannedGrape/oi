const fn='level';
var n,m,i,j,ans:word;
ss:array[1..1000,0..1000]of word;
procedure flink;
begin assign(input,fn+'.in');
assign(output,fn+'.out');
reset(input);rewrite(output) end;
procedure fclose;
begin close(output);close(input) end;

function can:boolean;
var i,j,k:word;flag:boolean;sn:array[0..1000]of word;

function cani(i:word):boolean;
var k,min,sum:word;
begin sum:=0;min:=maxint;
for k:=1 to ss[i,0] do
	if sn[k]<min then min:=sn[k];
for k:=1 to m do
	if sn[k]<min then inc(sum);
exit(sum=ss[i,0])
end;

begin
for i:=1 to n do begin 
	flag:=false;
sn[i]:=0;
while sn[i]<ans do begin inc(sn[i]);
		if cani(i) then begin flag:=true;break end end;
	if flag=false then exit(false) end;
exit(true)
end;
begin
flink;
readln(n,m);
for i:=1 to m do begin read(ss[i,0]);for j:=1 to ss[i,0] do read(ss[i,j]) end;
for ans:=1 to m do if can then break;
write(ans);
fclose
end.