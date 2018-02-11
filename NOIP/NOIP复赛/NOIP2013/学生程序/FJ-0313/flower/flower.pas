program ye;
var n,i,j,ji,ans,k:longint;
    h:array[0..100001] of longint;
    g,d:array[0..100001] of boolean;
    b:boolean;
procedure search(x:longint);
 var c:boolean;
     ii,a:longint;
 begin
  if k>5000000 then
   begin
    writeln(ans);
    close(input); close(output);
    halt;
   end;
  c:=b;
  inc(ji);
  if ji>ans then ans:=ji;
  a:=ans;
  if c then
   for ii:=x+1 to n do
    if h[ii]>h[x] then
     begin
      b:=not b;
      g[ii]:=true;
      inc(k);
      search(ii);
      b:=not b;
     end;
  if c=false then
   for ii:=x+1 to n do
    if h[ii]<h[x] then
     begin
      b:=not b;
      d[ii]:=true;
      inc(k);
      search(ii);
      b:=not b;
     end;
  dec(ji);
 end;
begin
 assign(input,'flower.in'); reset(input);
 assign(output,'flower.out'); rewrite(output);
 readln(n);
 k:=0;
 for i:=1 to n do read(h[i]);
 ji:=0;
 ans:=1;
 fillchar(g,sizeof(g),false);
 fillchar(d,sizeof(d),false);
 i:=1;
 repeat
  if d[i]=false then
   begin
    b:=true;
    search(i);
   end;
  if g[i]=false then
   begin
    b:=false;
    search(i);
   end;
  inc(i);
 until i>(n-ans);
 writeln(ans);
 close(input); close(output);
end.
