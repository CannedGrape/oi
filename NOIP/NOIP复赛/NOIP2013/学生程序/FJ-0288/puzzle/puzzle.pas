program puzzle;
const dx:array[1..4]of -1..1=(0,0,1,-1);
      dy:array[1..4]of -1..1=(1,-1,0,0);
var n,m,q,t1,t2,i,j,head,time,tail,min,min2,kx,ky,fx,fy,tx,ty:longint;
    head2,tail2:longint;t3,t4:longint;
    a,f,f2:array[-1..32,-1..32]of boolean; f1,f3:boolean;
    l,l2:array[1..10000,1..5]of longint;
begin
 assign(input,'puzzle.in');assign(output,'puzzle.out');
 reset(input);rewrite(output);
 readln(n,m,q); fillchar(a,sizeof(a),false);
 for i:=1 to n do
 begin
  for j:=1 to m do
  begin read(t1);
  if t1=0 then a[i,j]:=false
  else a[i,j]:=true;end;
  readln;
 end;
 for time:=1 to q do
 begin
   fillchar(f,sizeof(f),true);
   min:=0;min2:=0;
   readln(kx,ky,fx,fy,tx,ty);
   if (fx=tx)and(fy=ty) then begin
   if time=q then write(0) else writeln(0);continue;end;
   head:=0;tail:=1;f1:=false;
   l[1,1]:=kx;l[1,2]:=ky;f[kx,ky]:=false;
   if a[tx,ty] then
   while head<tail do
   begin
     inc(head);
     for i:=1 to 4 do
     begin
       t1:=l[head,1]+dx[i];
       t2:=l[head,2]+dy[i];
       if (a[t1,t2]=false)or(f[t1,t2]=false) then continue;
       inc(tail);
       l[tail,1]:=t1;l[tail,2]:=t2;
       l[tail,3]:=l[head,3]+1;
       f[t1,t2]:=false;
       if (t1=fx)and(t2=fy) then
       begin kx:=l[head,1];
       ky:=l[head,2];f1:=true;head:=maxlongint;break;end;
     end;
   end;
   if not(f1) then begin if time=q then write(-1) else
   writeln(-1);continue;end;
   min:=l[tail,3]-1;


   head:=0;tail:=1; fillchar(l,sizeof(l),0);
   l[1,1]:=fx;l[1,2]:=fy;f1:=false;
   l[1,4]:=kx;l[1,5]:=ky;
   fillchar(f,sizeof(f),true); f[fx,fy]:=false;min2:=maxlongint;
   while (head<tail)and(l[tail,3]<min2)do
   begin
     inc(head);
     for i:=1 to 4 do
     begin
       t1:=l[head,1]+dx[i];
       t2:=l[head,2]+dy[i];
       if (a[t1,t2]=false)or(f[t1,t2]=false) then continue;
       inc(tail);
       l[tail,1]:=t1;l[tail,2]:=t2;
       l[tail,3]:=l[head,3]+1;
       f[t1,t2]:=false;


       head2:=0;tail2:=1;fillchar(l2,sizeof(l2),0);
       l2[1,1]:=l[head,4];l2[1,2]:=l[head,5];f3:=false;
       fillchar(f2,sizeof(f2),true);f2[l[head,4],l[head,5]]:=false;
       f2[l[head,1],l[head,2]]:=false;
       if (l2[1,1]=l[tail,1])and(l2[1,2]=l[tail,2]) then f3:=true;
       if (l2[1,1]<>l[tail,1])or(l2[1,2]<>l[tail,2]) then
       while head2<tail2 do
       begin
         inc(head2);
         for j:=1 to 4 do
         begin
           t3:=l2[head2,1]+dx[j];
           t4:=l2[head2,2]+dy[j];
           if (a[t3,t4]=false)or(f2[t3,t4]=false) then continue;
           inc(tail2);
           l2[tail2,1]:=t3;l2[tail2,2]:=t4;
           l2[tail2,3]:=l2[head2,3]+1;
           f2[t3,t4]:=false;
           if (t3=l[tail,1])and(t4=l[tail,2]) then
           begin head2:=maxlongint;
           l[tail,3]:=l[tail,3]+l2[tail2,3];
           l[tail,4]:=l[head,1];
           l[tail,5]:=l[head,2];
           f3:=true;
           break;end;
         end;
       end;

       if not(f3) then dec(tail) else
       if (t1=tx)and(t2=ty) then
       begin
         if min2>l[tail,3] then min2:=l[tail,3];
         f1:=true;
       end;
     end;
   end;
   if f1 then
   begin if time=q then write(min+min2) else writeln(min+min2);end
   else begin if time=q then write(-1) else writeln(-1);end;
 end;
 close(input);close(output);
end.






















