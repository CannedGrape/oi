var
  a:array[0..100,0..100]of longint;
  b:array[0..1000]of longint;
  n,m,q,i,j,ex,ey,x1,x2,y1,y2,t,min:longint;
procedure f(x,y,c,d:longint);
  var
    p:longint;
  begin
    p:=0;
    if a[x2,y2]=2 then begin
                    if c<min then min:=c; exit; end;
    if c>300 then begin
                    if min=maxlongint then min:=-1; exit; end;
    if(a[x-1,y]>0)and(d<>1) then begin
                         t:=a[x-1,y]; a[x-1,y]:=a[x,y]; a[x,y]:=t;
                         f(x-1,y,c+1,2);
                         t:=a[x-1,y]; a[x-1,y]:=a[x,y]; a[x,y]:=t;
                         p:=1;
                       end;
    if(a[x+1,y]>0)and(d<>2) then begin
                         t:=a[x+1,y]; a[x+1,y]:=a[x,y]; a[x,y]:=t;
                         f(x+1,y,c+1,1);
                         t:=a[x+1,y]; a[x+1,y]:=a[x,y]; a[x,y]:=t;
                         p:=1;
                       end;
    if(a[x,y-1]>0)and(d<>3) then begin
                         t:=a[x,y-1]; a[x,y-1]:=a[x,y]; a[x,y]:=t;
                         f(x,y-1,c+1,4);
                         t:=a[x,y-1]; a[x,y-1]:=a[x,y]; a[x,y]:=t;
                         p:=1;
                       end;
    if(a[x,y+1]>0)and(d<>4) then begin
                         t:=a[x,y+1]; a[x,y+1]:=a[x,y]; a[x,y]:=t;
                         f(x,y+1,c+1,3);
                         t:=a[x,y+1]; a[x,y+1]:=a[x,y]; a[x,y]:=t;
                         p:=1;
                       end;
    if p=0 then exit;
  end;
begin
  assign(input,'puzzle.in');
  reset(input);
  assign(output,'puzzle.out');
  rewrite(output);
  readln(n,m,q);
  for i:=1 to n do
    for j:=1 to m do
      read(a[i,j]);
  for i:=1 to q do
    begin
      min:=maxlongint;
      readln(ex,ey,x1,y1,x2,y2);
      a[x1,y1]:=2;
      f(ex,ey,0,0);
      b[i]:=min;
      a[x1,y1]:=1;
    end;
  for i:=1 to q do writeln(b[i]);
  close(input);
  close(output);
end.
