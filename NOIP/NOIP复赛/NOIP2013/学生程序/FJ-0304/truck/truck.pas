program ex;
var way:array[1..1000000,0..3]of longint;
i,j,k,l,n,m,head,tail,max,s,t,mid,ans:longint;
a,last:array[1..10000]of longint;
c:array[1..10000]of boolean;

procedure dfs(k,l:longint);
var i:longint;
begin
if c[k] then exit
else c[k]:=true;
i:=last[k];
while i<>0 do
begin
if way[i,3]>=l then
dfs(way[i,2],l);
i:=way[i,0];
end;
end;

function check(l:longint):boolean;
var j,i:longint;
begin
j:=1;
fillchar(c,sizeof(c),false);
dfs(s,l);
if c[t] then exit(true)
else exit(false);
end;

begin
assign(input,'truck.in');reset(input);
assign(output,'truck.out');rewrite(output);
read(n,m);
for i:=1 to m do
begin
read(way[i*2-1,1],way[i*2-1,2],way[i*2-1,3]);
way[i*2-1,0]:=last[way[i*2-1,1]];
last[way[i*2-1,1]]:=i*2-1;
way[i*2,1]:=way[i*2-1,2];
way[i*2,2]:=way[i*2-1,1];
way[i*2,3]:=way[i*2-1,3];
way[i*2,0]:=last[way[i*2,1]] ;
last[way[i*2,1]]:=i*2;
if way[i*2-1,3]>max then max:=way[i*2-1,3];
end;
readln(k);
for i:=1 to k do
begin
head:=0;tail:=max+1;ans:=-1;
read(s,t);
while head+1<tail do
begin
mid:=(head+tail)div 2;
if check(mid) then begin head:=mid;ans:=mid;end
else tail:=mid-1;
end;
writeln(ans);
end;
close(input);
close(output);
end.