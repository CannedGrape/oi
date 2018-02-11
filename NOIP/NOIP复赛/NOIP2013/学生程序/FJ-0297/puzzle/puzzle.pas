{$R+,Q+,S+}
const a:array[1..4,1..2] of integer=((1,0),(-1,0),(0,1),(0,-1));

var map:array[0..31,0..34] of integer;
    line:array[1..500000,0..4] of integer;
    ex,ey,sx,sy,tx,ty:integer;
    i,j,n,m,q:longint;
    ans:int64;

function check(k,x1,y1,x2,y2:longint):boolean;
 var i:longint;
 begin
   for i:=1 to k-1 do
    if (line[i,1]=x1) and (line[i,2]=y1) and (line[i,3]=x2) and (line[i,4]=y2) then
     exit(false);
   exit(true);
 end;

procedure bfs;
 var t,h,i,x1,y1,x2,y2:longint;
 begin
   line[1,0]:=0;
   line[1,1]:=ex;line[1,2]:=ey;
   line[1,3]:=sx;line[1,4]:=sy;
   h:=0;t:=1;
   repeat
     inc(h);
     if (line[h,3]=tx) and (line[h,4]=ty) then
      begin
        ans:=line[h,0];
        exit;
      end;
     for i:=1 to 4 do
      if (map[line[h,1]+a[i,1],line[h,2]+a[i,2]]<>0) then
       begin
         x1:=line[h,1]+a[i,1];
         y1:=line[h,2]+a[i,2];
         if (line[h,1]+a[i,1]=line[h,3]) and (line[h,2]+a[i,2]=line[h,4]) then
          begin
            x2:=line[h,1];
            y2:=line[h,2];
          end
         else
          begin
            x2:=line[h,3];
            y2:=line[h,4];
          end;
         if check(h,x1,y1,x2,y2) then
          begin
           inc(t);
           line[t,0]:=line[h,0]+1;
           line[t,1]:=x1;
           line[t,2]:=y1;
           line[t,3]:=x2;
           line[t,4]:=y2;
          end;
        end;
   until h=t;
 end;

begin
  assign(input,'puzzle.in');reset(input);
  assign(output,'puzzle.out');rewrite(output);
  readln(n,m,q);
  fillchar(map,sizeof(map),0);
  for i:=1 to n do
   begin
     for j:=1 to m do read(map[i,j]);
     readln;
   end;
  for i:=1 to q do
   begin
     readln(ex,ey,sx,sy,tx,ty);
     fillchar(line,sizeof(line),0);
     ans:=-1;
     bfs;
     writeln(ans);
   end;
  close(input);close(output);
end.

