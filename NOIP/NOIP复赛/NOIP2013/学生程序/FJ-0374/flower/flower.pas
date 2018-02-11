var h:array[1..100000] of longint;
    g:array[1..100000] of boolean;
    mix,xymix,i,n,ans1,ans2,ans:longint;
 procedure pd1(k:longint);
  var j:longint;
   begin
    if (k<=1) or (k>=n) then exit;
    j:=1;
    repeat
     if k-j<1 then break;
     if (g[k]) and (g[k-j]) and (h[k]<h[k-j]) then
      begin
       pd1(k-j);
       break;
      end else
      begin
       g[k-j]:=false;
       inc(j);
      end;
    until (k-j<1);
   end;
 procedure pd2(k:longint);
  var j:longint;
   begin
    if (k<=1) or (k>=n) then exit;
    j:=1;
    repeat
     if k+j>n then break;
     if (g[k]) and (g[k+j]) and (h[k]<h[k+j]) then
      begin
       pd2(k+j);
       break;
      end else
      begin
       g[k+j]:=false;
       inc(j);
      end;
    until (k+j>n);
   end;
 procedure pd3(k:longint);
  var j:longint;
   begin
    if (k<=1) or (k>=n) then exit;
    j:=1;
    repeat
     if k-j<1 then break;
     if (g[k]) and (g[k-j]) and (h[k]>h[k-j]) then
      begin
       pd3(k-j);
       break;
      end else
      begin
       g[k-j]:=false;
       inc(j);
      end;
    until (k-j<1);
   end;
 procedure pd4(k:longint);
  var j:longint;
   begin
    if (k<=1) or (k>=n) then exit;
    j:=1;
    repeat
     if k+j>n then break;
     if (g[k]) and (g[k+j]) and (h[k]>h[k+j]) then
      begin
       pd4(k+j);
       break;
      end else
      begin
       g[k+j]:=false;
       inc(j);
      end;
    until (k+j>n);
   end;
 begin
  assign(input,'flower.in');
  assign(output,'flower.out');
  reset(input);
  rewrite(output);
  readln(n);
  for i:=1 to n do
   read(h[i]);
  mix:=h[1];
  xymix:=1;
  for i:=1 to n do
   if h[i]<mix then
    begin
     mix:=h[i];
     xymix:=i;
    end;
  fillchar(g,sizeof(g),true);
  pd1(xymix);
  pd2(xymix);
  ans1:=0;
  for i:=1 to n do
   if not g[i] then inc(ans1);
  mix:=h[1];
  xymix:=1;
  for i:=1 to n do
   if h[i]>mix then
    begin
     mix:=h[i];
     xymix:=i;
    end;
  fillchar(g,sizeof(g),true);
  pd3(xymix);
  pd4(xymix);
  ans2:=0;
  for i:=1 to n do
   if not g[i] then inc(ans2);
  if ans1>ans2 then ans:=n-ans2 else ans:=n-ans1;
  writeln(ans);
  close(input);
  close(output);
 end.