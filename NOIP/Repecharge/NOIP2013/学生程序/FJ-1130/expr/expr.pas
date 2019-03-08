program expr;

const MAXN=1000005;

var
 q1:array[0..MAXN]of int64;
 q2:array[0..MAXN]of char;
 b1,b2,b3,h1,h2,j:int64;
 i:longint;
 s:ansistring;
 t1,t2,t3:ansistring;

procedure work(var i:longint);
begin
 j:=i+1;
 while (s[j] in['0'..'9']) and (j<length(s)-1) do inc(j);
 t1:=copy(s,i,j-i);
 val(t1,b1);
 inc(h1); q1[h1]:=b1;
 i:=j;
end;

begin
 assign(input,'expr.in'); reset(input);
 assign(output,'expr.out'); rewrite(output);
 readln(s);
 i:=1;
 while i<=length(s) do
 begin
  if s[i] in['0'..'9'] then work(i)
  else if s[i]='*' then
  begin
   inc(i);
   work(i);
   b2:=q1[h1]*q1[h1-1];
   h1:=h1-1;
   q1[h1]:=b2;
  end
  else if s[i]='+' then
  begin
   inc(h2);
   q2[h2]:='+';
   inc(i);
  end;
 end;
 for i:=1 to h2 do
 begin
  b2:=q1[h1]+q1[h1-1];
  h1:=h1-1;
  q1[h1]:=b2;
 end;
 str(q1[h1],t2);
 if length(t2)<=4 then writeln(t2)
 else
 begin
  t3:=copy(t2,length(t2)-3,4);
  while pos('0',t3)=1 do delete(t3,1,1);
  if t3='' then writeln('0') else writeln(t3);
 end;
 close(input); close(output);
end.
