var
  n,m,i,j,k,q,tot,ans,max,min,head,tail:longint;
  x,y,z:longint;
  first,next,endl,w:array[0..50000] of longint;
  dis:array[0..50000] of longint;
  bo:array[0..50000] of boolean;
  t:array[0..100000] of longint;



procedure setl(x,y,z:longint);
begin
  inc(tot);
  next[tot]:=first[x];
  first[x]:=tot;
  endl[tot]:=y;
  w[tot]:=z;
end;












procedure spfa(x:longint);
var
  i,j,k,l:longint;
begin
  fillchar(dis,sizeof(dis),$7f div 3);
  fillchar(bo,sizeof(bo),false);
  t[1]:=x; head:=0; tail:=1; dis[x]:=0;
  bo[x]:=true;
  repeat
    inc(head);
    bo[t[head]]:=false;
    k:=first[x];
    l:=endl[k];
    while k<>0 do
     begin
       if dis[l]>dis[t[head]]+w[k] then
        begin
          dis[l]:=dis[t[head]]+w[k];
          if min>w[k] then min:=w[k];
          if bo[l]=false then
           begin
             inc(tail);
             t[tail]:=l;
             bo[l]:=true;
           end;
        end;
       k:=next[k];
       l:=endl[k];
     end;
  until head>=tail;

end;
















begin
assign(input,'truck.in'); reset(input);
assign(output,'truck.out'); rewrite(output);
  readln(n,m);
  for i:=1 to m do
   begin
     readln(x,y,z);
     setl(x,y,z);
     setl(y,x,z);
   end;





  readln(q);
  for i:=1 to q do
   begin
     readln(x,y);
     min:=maxlongint div 3;
     spfa(x);
     if dis[y]>maxlongint div 3 then
      begin
        writeln(-1);
        continue;
      end;

     //writeln('dis[y]',dis[y]);
     writeln(min);

   end;
close(input); close(output);
end.

