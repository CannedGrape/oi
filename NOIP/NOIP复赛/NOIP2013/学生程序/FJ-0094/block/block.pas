program block;
var
 a,b:array[1..100000] of integer;
 c,d,j,i,m,n,s:integer;

procedure js(c,s:integer);
var
 p,q,w,x,y,z,e,f:integer;
begin
 p:=0;
 for x:=c to s do
  if b[x]>p then
   begin
    p:=b[x];
    q:=x;
   end;
 e:=-1;
 f:=-1;
 if q>1 then e:=b[q]-b[q-1];
 if q<s then f:=b[q]-b[q+1];
 if e<0 then e:=0;
 if f<0 then f:=0;
 w:=0;
 if q>c then for x:=c to q-1 do if p=b[x] then w:=x;
 if w<>0
  then begin if w>c then js(c,w-1); if w<q-1 then js(w+1,q-1); end
  else if q>c then js(c,q-1);
 z:=0;
 if s>q then for y:=q+1 to s do if p=b[y] then z:=y;
 if z<>0 then
  begin if z>q+1 then js(q+1,w-1); if z<s then js(w+1,s); end
  else if q<s then js(q+1,s);
 m:=m+e+f;
 for x:=c to q-1 do b[x]:=b[x]+e;
 for x:=q+1 to s do b[x]:=b[x]+f;
end;

begin
 assign(input,'block.in');
 assign(output,'block.out');
 reset(input);
 rewrite(output);
 readln(n);
 for i:=1 to n do read(a[i]);
 readln;
 for i:=1 to n do b[i]:=a[i];
 c:=1;
 m:=0;
 js(c,n);
 writeln(m);
 readln;
 close(input);
 close(output);
end.
