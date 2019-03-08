const dx:array[1..4]of longint=(0,0,1,-1);
      dy:array[1..4]of longint=(-1,1,0,0);

var hash:array[1..1000050]of boolean;
    use:array[-1..35,-1..35]of boolean;
    ex,ey,sx,sy,tx,ty,n,m,i,j,min,zhi,q,num:longint;

function ha(a,b,c,d:longint):longint;
begin
  ha:=a*(2*a*1000+3*b*100+4*c*10+d*5) mod zhi;
end;

procedure search(q,p,c:longint);
var i,x,y,h:longint;
    pd:boolean;
begin
  if c>20 then exit;
  if (sx=tx)and(sy=ty)and(c-1<min) then
    begin
      min:=c-1;
      exit;
    end;
  for i:=1 to 4 do
    begin
      x:=q+dx[i];y:=p+dy[i];
      h:=ha(x,y,sx,sy);
      if use[x,y] then
        begin
          pd:=false;
          if (x=sx)and(y=sy) then
            begin
              sx:=q;sy:=p;
              pd:=true;
            end;
          h:=ha(x,y,sx,sy);
          if  not hash[h] then
            begin
              hash[h]:=true;
              search(x,y,c+1);
            end;
          if pd then
            begin
              sx:=sx+dx[i];
              sy:=sy+dy[i];
            end;
        end;
    end;
end;

begin
assign(input,'puzzle.in');reset(input);
assign(output,'puzzle.out');rewrite(output);
  zhi:=1000007;
  readln(n,m,q);
  for i:=1 to n do
    for j:=1 to m do
      begin
        read(num);
        if num=1 then
          use[i,j]:=true
          else
          use[i,j]:=false;
      end;
  for i:=1 to q do
    begin
      readln(ex,ey,sx,sy,tx,ty);
      min:=maxlongint;
      for j:=1 to 1000050 do
        hash[j]:=false;
      hash[ha(ex,ey,sx,sy)]:=true;
      search(ex,ey,1);
      hash[ha(ex,ey,sx,sy)]:=false;
      if min<100 then
      writeln(min)
      else writeln('-1');
    end;
    close(input);close(output);
end.
