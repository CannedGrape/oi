const fn='number';
var  nums:array[1..1000000]of longint;
stars:array[1..1000000]of int64;
scores:array[1..1000000]of int64;
i,n,p:longword;max:int64;
procedure flink;
begin assign(input,fn+'.in');
assign(output,fn+'.out');
reset(input);rewrite(output) end;
procedure fclose;
begin close(output);close(input) end;

function getmax(i:longword):int64;
begin getmax:=scores[1]+stars[1];for i:=2 to i do if scores[i]+stars[i]>getmax then getmax:=scores[i]+stars[i] end;
	
function maxx(a,b:int64):int64;begin if a>=b then exit(a) else exit(b) end;

function maxxxstr(x:longword):int64;
var i:longword;
 sum:array[0..1000000]of int64;
begin 
for i:=1 to x do {	sum[i]:=maxx(sum[i-1]+nums[i],nums[i]);}
	if sum[i]<0 then sum[i]:=nums[i]
else sum[i]:=sum[i-1]+nums[i];
maxxxstr:=sum[1];
for i:=2 to x do
	if sum[i]>maxxxstr then maxxxstr:=sum[i]
end;
begin
flink;
readln(n,p);read(nums[1]);stars[1]:=maxxxstr(1);scores[1]:=stars[1];
for i:=2 to n do begin read(nums[i]);
	stars[i]:=maxxxstr(i);
scores[i]:=getmax(i-1)
	end;
  max:=scores[1];
	for i:=1 to n do if scores[i]>max then max:=scores[i];
 	write(max mod p) ;
fclose
end.