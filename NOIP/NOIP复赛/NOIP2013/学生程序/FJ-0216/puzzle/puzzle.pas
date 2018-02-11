const
  w:array[1..4,1..2]of longint=((1,0),(0,1),(-1,0),(0,-1));

var
  a:array[0..31,0..31]of longint;
  f:array[1..30,1..30,1..30,1..30]of boolean;
  b,c:array[1..1000000,1..2]of longint;
  e:array[1..1000000]of longint;
  m,n,q,i,j,k,h,t,x1,x2,y1,y2,t1,t2,x,y:longint;

begin
  assign(input,'puzzle.in');reset(input);
  assign(output,'puzzle.out');rewrite(output);
  readln(n,m,q);
  for i:=1 to n do
    for j:=1 to m do read(a[i,j]);
  for i:=1 to q do begin
    fillchar(f,sizeof(f),true);
    readln(t1,t2,x1,y1,x2,y2);
    h:=1;
    t:=1;
    f[t1,t2,x1,y1]:=false;
    b[1,1]:=t1;
    b[1,2]:=t2;
    c[1,1]:=x1;
    c[1,2]:=y1;
    e[1]:=0;
    repeat
      if (c[h,1]=x2) and (c[h,2]=y2) then begin
        writeln(e[h]);
        break;
      end;
      for j:=1 to 4 do begin
        x:=b[h,1]+w[j,1];
        y:=b[h,2]+w[j,2];
        if a[x,y]=1 then begin
          if (x=c[h,1]) and (y=c[h,2]) then begin
            if f[x,y,b[h,1],b[h,2]] then begin
              inc(t);
              b[t,1]:=x;
              b[t,2]:=y;
              c[t,1]:=b[h,1];
              c[t,2]:=b[h,2];
              f[x,y,b[h,1],b[h,2]]:=false;
              e[t]:=e[h]+1;
            end;
          end else if (x>=1) and (x<=n) and (y>=1) and (y<=m) then begin
            if f[x,y,c[h,1],c[h,2]] then begin
              inc(t);
              b[t,1]:=x;
              b[t,2]:=y;
              c[t,1]:=c[h,1];
              c[t,2]:=c[h,2];
              f[x,y,c[h,1],c[h,2]]:=false;
              e[t]:=e[h]+1;
            end;
          end;
        end;
      end;
      inc(h);
    until h>t;
    if h>t then writeln(-1);
  end;
  close(input);
  close(output);
end.



