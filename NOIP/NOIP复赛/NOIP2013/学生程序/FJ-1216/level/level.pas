var
 f:array[1..1000] of longint;
 a:array[0..1500,0..1000] of longint;
 wo,h,l,i,j,x,m,n,ta,yh:longint;
 f1:array[1..1000] of boolean;
  zj:boolean;
 function ai(o:longint):boolean;
  var
   i,j:longint;
  begin
   for i:=1 to n do
    f[i]:=1;
   for i:=1 to a[1,0] do
    inc(f[a[1,i]]);
   for i:=2 to m do
    begin
     yh:=1;
     repeat
     zj:=true;
     for j:=1 to a[i,0] do
      begin
       if f[a[i,j]]<f[yh] then
         yh:=a[i,j];
       f1[a[i,j]]:=true;
      end;
    for j:=a[i,1] to a[i,a[i,0]] do
     if (not(f1[j]))and(f[j]>=yh) then
      begin
       inc(f[yh]);
       zj:=false;
       if f[yh]>o then exit(false);
      end;
    until zj;
    end;
   exit(true);
  end;
begin
 assign(input,'level.in'); reset(input);
 assign(output,'level.out'); rewrite(output);
 readln(n,m);
 l:=0; ta:=maxlongint;
 for i:=1 to m do
  begin
   read(x);
   a[i,0]:=x;
   for j:=1 to x do
    read(a[i,j]);
   if x>l then l:=x;
  end;
 h:=1;
 repeat
  wo:=(h+l) div 2;
  if ai(wo) then
   begin
    l:=wo-1;
    if wo<ta then ta:=wo;
   end
  else h:=wo+1;
 until h>=l;
 writeln(ta);
 close(input); close(output);
end.
