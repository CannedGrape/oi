const
   w:array[1..4] of longint=(-1,0,1,0);
   u:array[1..4] of longint=(0,1,0,-1);
var
     i,j,q,n,m,head,tail,sx,sy,tx,ty,ex,ey:longint;
     map:array[1..30,1..30] of longint;
     bo:array[-1..32,-1..32] of boolean;
     f:array[1..1000000,1..5] of longint;
function bfs:longint;
var
   i,xx,yy:longint;
begin
    head:=0;
    tail:=1;
    f[1,1]:=ex; f[1,2]:=ey; f[1,3]:=sx; f[1,4]:=sy; f[1,5]:=0;
    while (head<>tail) do
    begin
     inc(head);
      for i:=1 to 4 do
      begin
       xx:=f[head,1]+w[i]; yy:=f[head,2]+u[i];
       if bo[xx,yy] then
        begin
         inc(tail);
         f[tail,1]:=xx; f[tail,2]:=yy;
         f[tail,3]:=f[head,3]; f[tail,4]:=f[head,4];
         f[tail,5]:=f[head,5]+1;
         if (xx=sx) and (yy=sy) then
          begin
          f[tail,3]:=f[head,1]; f[tail,4]:=f[head,2];
          end;
         if (xx=tx) and (yy=ty) and (abs(f[tail,3]-tx)=1) and  (abs(f[tail,4]-ty)=1) then
         exit(f[tail,5]);
        end;
      end;
      if head>500000 then exit(-1);
    end;
end;

begin
assign(input,'puzzle.in');
assign(output,'puzzle.out');
reset(input); rewrite(output);
  fillchar(bo,sizeof(bo),false);
  readln(n,m,q);
  for i:=1 to n do
   for j:=1 to m do
   begin
    read(map[i,j]);
    if map[i,j]=1  then bo[i,j]:=true;
   end;
  for i:=1 to q do
begin
  readln(ex,ey,sx,sy,tx,ty);
  writeln(bfs);
end;



close(input); close(output);
end.
