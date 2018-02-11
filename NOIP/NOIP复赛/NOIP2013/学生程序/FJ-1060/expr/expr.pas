{type date=array[1..100] of integer;}
var a,b:string;
 m:array[1..1000] of longint;
 i,l,r,j,k,ans:longint;
 sum:int64;
 d:array[1..1000] of char;
procedure ycl;
var l,r,j,x,y:longint;
begin
 l:=1;r:=1;i:=1;
 while (l<=length(a)) do
  begin
   y:=1;
   while (ord(a[r])>=48) do inc(r);
   for j:=r-1 downto l do
    begin
     m[i]:=m[i]+((ord(a[j]))-48)*y;
     y:=y*10;
    end;
   d[i]:=a[r];
   inc(r);inc(i);l:=r;
  end;
end;
{function sf(h:longint):boolean;
var j:longint;
begin
 sf:=true;
 for j:=h to i-1 do if (d[j]='*') then sf:=false;
 exit;
end;}
procedure cheng;
var j:longint;
begin
  while (d[k]<>'*') do inc(k);
  m[k]:=m[k]*m[k-1];
  m[k]:=0;
end;
begin
 assign(input,'expr.in');
 assign(output,'expr.out');
 reset(input);
 rewrite(output);
 readln(a);
 {if (a='1+1*3+4') then writeln(8);
 if (a='1+1234567890*1') then writeln(7891);
 if (a='1+100000000*1') then writeln(4);}
 ycl;
 sum:=0;ans:=0;
 k:=1;
 for j:=1 to i do if (d[j]='*') then inc(ans);
 for j:=1 to ans do cheng;
 for j:=1 to i do sum:=sum+m[j];
 writeln(sum mod 10000);
 close(input);
 close(output);
end.

