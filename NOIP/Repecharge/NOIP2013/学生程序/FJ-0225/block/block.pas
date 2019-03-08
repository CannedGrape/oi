program block;
var
 n,i:longint;
 ans:int64;
 h:array[1..100000] of longint;

procedure fin;
begin
 assign(input,'block.in'); reset(input);
 assign(output,'block.out'); rewrite(output);
end;

procedure fout;
begin
 close(input);
 close(output);
end;

procedure search(l,r:longint);
var
 p,q,i,mid:longint;
 flag,bo:boolean;
begin
 p:=maxlongint;
 q:=-maxlongint;
 flag:=true;
 for i:=l to r do
 begin
  if h[i]<p then
  begin
   p:=h[i];
   mid:=i;
  end;
  if h[i]>q then q:=h[i];
 end;
 if p<>q then flag:=false;
 ans:=ans+p;
 if flag then exit;
 for i:=l to r do h[i]:=h[i]-p;
 if l<mid then search(l,mid-1);
 if r>mid then search(mid+1,r);
end;

begin
 fin;
 readln(n);
 for i:=1 to n do read(h[i]);
 search(1,n);
 writeln(ans);
 fout;
end.
