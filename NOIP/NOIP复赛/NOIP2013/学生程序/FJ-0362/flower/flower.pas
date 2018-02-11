const w:array[1..4] of integer=(1,0,-1,0);
      z:array[1..4] of integer=(0,1,0,-1);

var n,m,q,x,y,t,i:integer;  ans:longint;
    h:array[1..50,1..50] of integer;
    ex,ey,sx,sy,tx,ty,p:array[1..600] of integer;

procedure  try(ex,ey:integer);
   var u:integer;
begin
  t:=1;
   repeat
    while h[ex+w[t],ey+z[t]]<>0 do
    while h[tx[i],ty[i]]<>2  do
     begin
      h[ex+w[t],ey+z[t]]:=2; inc(ans);
      try(ex+w[t],ey+z[t]);
     end;
     p[t]:=ans;
    inc(t);

    until t=4;
    for t:=1 to 3 do
     for u:=t+1 to 4 do
      if p[t]<p[u] then ans:=p[t];
end;


begin
  assign(input,'pazzle.in');  reset(input);
  assign(output,'pazzle.out');  rewrite(output);
  readln(n,m,q);
  for x:=1 to n do
   begin
    for y:=1 to m do
     read(h[x,y]);  readln;
  end;

  for i:=1 to q do
   readln(ex[i],ey[i],sx[i],sy[i],tx[i],ty[i]);

   h[ex[i],ey[i]]:=2; h[sx[i],sy[i]]:=3; h[tx[i],ty[i]]:=4;

  i:=1;  ans:=0;
   repeat
    for t:=1 to 4 do begin
     if h[sx[i]+w[t],sy[i]+z[t]]=0 then begin
      writeln(-1); inc(i);
     end;

     if h[tx[i]+w[t],ty[i]+z[t]]=0 then begin
      writeln(-1); inc(i);
     end;

     if h[ex[i]+w[t],ey[i]+z[t]]=0 then begin
      writeln(-1); inc(i);
     end;
    end;


    try(ex[i],ey[i]);
     for t:=1 to 4 do
      if (h[tx[i]+w[t],ty[i]+z[t]]=0) or  (h[tx[i]+w[t],ty[i]+z[t]]=4)
       then begin  writeln(-1); inc(i); end
       else ans:=ans+abs(sx[i]-tx[i])+abs(sy[i]-ty[i]);
       writeln(ans);


   until i=q;
  close(input);   close(output);
end.
