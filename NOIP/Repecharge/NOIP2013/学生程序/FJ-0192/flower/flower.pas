uses math;
const Ln=100000+10;
      Lh=1 shl 21;
var d:array[0..Lh,0..1]of longint;
    n,m,h,minh,maxh:longint;
    ans:longint;
//
Function calc(l,r,x:longint):longint;
  begin
    if r-l<=1 then exit(0);
    calc:=0;
    while l xor r<>1 do
    begin
      if l and 1=0 then calc:=max(calc,d[l+1][x]);
      if r and 1=1 then calc:=max(calc,d[r-1][x]);
      l:=l shr 1;
      r:=r shr 1;
    end;
  end;
//
Procedure update(x:longint);
  begin
    while x>1 do
    begin
      x:=x shr 1;
      d[x][0]:=max(d[x*2][0],d[x*2+1][0]);
      d[x][1]:=max(d[x*2][1],d[x*2+1][1]);
    end;
  end;
//
begin
  assign(input,'flower.in');reset(input);
  assign(output,'flower.out');rewrite(output);
  //
  fillchar(d,sizeof(d),0);
  ans:=1;m:=1 shl 20;maxh:=m;minh:=m*2;
  //
  readln(n);
  repeat
    read(h);inc(h,m+1);
    minh:=min(minh,h);
    maxh:=max(maxh,h);
    d[h][0]:=calc(minh-1,h,1)+1;
    d[h][1]:=calc(h,maxh+1,0)+1;
    update(h);
    dec(n);
  until n=0;
  writeln(max(d[1][0],d[1][1]));
  //
  close(input);close(output);
end.
