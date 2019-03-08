var n,m,q,x,y,z,i,j:longint;
    a,ans:array[1..5500,1..5500] of longint;
    v:array[1..5500] of boolean;
    d:array[0..11000] of longint;
    w:array[1..5500] of longint;
function min(a,b:longint):longint;
 begin
   if a<b then exit(a)
   else exit(b);
 end;
procedure spfa(s,t:longint);
 var i,head,tail,t1,h1,now:longint;
 begin
   fillchar(v,sizeof(v),true);
   for i:=1 to n do w[i]:=-1;
   head:=0;tail:=0;
   h1:=0;t1:=0;
   d[head]:=s;
   w[s]:=maxlongint;
   v[s]:=false;
   while h1<=t1 do
    begin
      now:=d[head mod n];
      for i:=1 to n do
       if (a[now,i]>-1) and (w[i]<min(w[now],a[now,i])) then
        begin
          w[i]:=min(w[now],a[now,i]);
          if v[i] then
           begin
             tail:=(tail+1) mod n;
             t1:=t1+1;
             d[tail]:=i;
             v[i]:=false;
           end;
        end;
      inc(h1);
      head:=(head+1) mod n;
      v[now]:=true;
   end;
 end;
begin
  assign(input,'truck.in');reset(input);
  assign(output,'truck.out');rewrite(output);
  readln(n,m);
  for i:=1 to n do
   for j:=1 to n do
    begin
      a[i,j]:=-1;
      ans[i,j]:=-1;
    end;
  for i:=1 to m do
   begin
     readln(x,y,z);
     if a[x,y]<z then
      begin
        a[x,y]:=z;
        a[y,x]:=z;
      end;
   end;
  readln(q);
  for i:=1 to q do
   begin
     readln(x,y);
     if ans[x,y]=-1 then
      begin
        spfa(x,y);
        ans[x,y]:=w[y];
        ans[y,x]:=ans[x,y];
      end;
     writeln(ans[x,y]);
   end;
  close(input);close(output);
end.

