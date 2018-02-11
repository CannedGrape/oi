program truck;
var i,j,t1,t2,t3,n,m,time,q,head,tail:longint;
    a:array[1..10001,1..1001,1..2]of longint;
    num:array[1..10000]of longint;
    l:array[0..10001,1..3]of longint;
    c,d:array[1..30000]of longint; f:boolean;
function min(x,y:longint):longint;
begin
 if x>y then exit(y)
 else exit(x);
end;
function max(x,y:longint):longint;
begin
 if x>y then exit(x)
 else exit(y);
end;
begin
 assign(input,'truck.in');
 assign(output,'truck.out');
 reset(input);
 rewrite(output);
 readln(n,m);
 for i:=1 to m do
 begin
   readln(t1,t2,t3);
   inc(num[t1]);inc(num[t2]);
   a[t1,num[t1],1]:=t2;a[t2,num[t2],1]:=t1;
   a[t1,num[t1],2]:=t3;a[t2,num[t2],2]:=t3;
   for j:=1 to num[t1]-1 do
    if (a[t1,j,1]=t2)
    then begin
           a[t1,j,2]:=max(a[t1,j,2],t3);
           a[t2,j,2]:=max(a[t2,j,2],t3);
           dec(num[t1]);dec(num[t2]);
           break;
         end;
 end;
 readln(q);
 for i:=1 to q do readln(c[i],d[i]);
 for time:=1 to q do
 begin
   head:=0;tail:=1;fillchar(l,sizeof(l),0);m:=-1;
   l[1,1]:=c[time];l[1,2]:=maxlongint;
   while head<tail do
   begin
     inc(head);
     for i:=1 to num[l[head,1]] do
     begin
       inc(tail);
       l[tail,1]:=a[l[head,1],i,1];
       l[tail,2]:=min(a[l[head,1],i,2],l[head,2]);
       l[tail,3]:=l[head,1];
       j:=l[tail,3];t1:=tail;
       if l[tail,1]=d[time] then begin
       m:=max(m,l[tail,2]);dec(tail);end
       else begin
       if l[tail,1]=c[time] then dec(tail)
       else
       while (j<>c[time])and(j<>0) do
       begin
         j:=l[t1,3];
         t1:=j;
         if j=l[tail,1] then
         begin dec(tail);break;end;
       end;
            end;
     end;
   end;
   writeln(m);
 end;
 close(input);close(output);
end.
