program flower;
uses math;
var
 n,i,ans,count:longint;
 h:array[1..100000] of longint;
 f1,f2:array[0..100000,1..5] of longint;

procedure fin;
begin
 assign(input,'flower.in'); reset(input);
 assign(output,'flower.out'); rewrite(output);
end;

procedure fout;
begin
 close(input);
 close(output);
end;

function print1(k:longint):longint;
begin
 count:=0;
 if (f2[k,4]>0) or (k=1) then inc(count);
 if f1[k,4]>0 then print1(f1[k,4]);
 print1:=count;
end;

function print2(k:longint):longint;
begin
 count:=0;
 if (f1[k,5]>0) or (k=n) then inc(count);
 if f2[k,5]>0 then print2(f2[k,5]);
 print2:=count;
end;

function print3(k:longint):longint;
begin
 count:=0;
 if (f1[k,4]>0) or (k=1) then inc(count);
 if f2[k,4]>0 then print3(f2[k,4]);
 print3:=count;
end;

function print4(k:longint):longint;
begin
 count:=0;
 if (f2[k,5]>0) or (k=n) then inc(count);
 if f1[k,5]>0 then print4(f1[k,5]);
 print4:=count;
end;

procedure dp1;
var
 i,j:longint;
begin
 fillchar(f1,sizeof(f1),0);
 for i:=1 to n do
 begin
  f1[i,1]:=h[i];
  f1[i,2]:=1;
  f1[i,3]:=1;
  f1[i,4]:=0;
  f1[i,5]:=0;
 end;
 for i:=2 to n do
  for j:=1 to i-1 do
   if f1[i,1]>f1[j,1] then
    if f1[i,2]<=f1[j,2] then
    begin
     f1[i,2]:=f1[j,2]+1;
     f1[i,4]:=j;
    end;
 for i:=n-1 downto 1 do
  for j:=n downto i+1 do
   if f1[i,1]>f1[j,1] then
    if f1[i,3]<=f1[j,3] then
    begin
     f1[i,3]:=f1[j,3]+1;
     f1[i,5]:=j;
    end;
end;

procedure dp2;
var
 i,j:longint;
begin
 fillchar(f2,sizeof(f2),0);
 for i:=1 to n do
 begin
  f2[i,1]:=h[i];
  f2[i,2]:=1;
  f2[i,3]:=1;
  f2[i,4]:=0;
  f2[i,5]:=0;
 end;
 for i:=2 to n do
  for j:=1 to i-1 do
   if f2[i,1]<f2[j,1] then
    if f2[i,2]<=f2[j,2] then
    begin
     f2[i,2]:=f2[j,2]+1;
     f2[i,4]:=j;
    end;
 for i:=n-1 downto 1 do
  for j:=n downto i+1 do
   if f2[i,1]<f2[j,1] then
    if f2[i,3]<=f2[j,3] then
    begin
     f2[i,3]:=f2[j,3]+1;
     f2[i,5]:=j;
    end;
end;

function huiwen:boolean;
var
 i,j:longint;
begin
 i:=1;
 j:=n;
 while (h[i]=h[j]) and (i<=j) do
 begin
  inc(i);
  dec(j);
 end;
 if i>=j then exit(true) else exit(false);
end;

begin
 fin;
 readln(n);
 if n=1 then
 begin
  writeln(1);
  fout;
  halt;
 end;
 for i:=1 to n do read(h[i]);
 if huiwen then
 begin
  writeln(n);
  fout;
  halt;
 end;
 dp1;
 dp2;
 ans:=-maxlongint;
 for i:=1 to n do ans:=max(ans,max(print1(i)+print2(i),print3(i)+print4(i))+1);
 writeln(ans);
 fout;
end.