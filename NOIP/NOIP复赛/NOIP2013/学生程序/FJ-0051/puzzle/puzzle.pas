var
   first,next,endl,dis,a:array[0..5000]of longint;
   bo:array[0..32,0..32]of boolean;
   b:array[0..5000]of boolean;
   i,j,k,m,n,ans,head,tail,tot,s,t,q,x,y,x1,y1,x2,y2,ss,tt,yy,yyy:longint;
   boo:boolean;
function cao(x,y:longint):longint;
begin
  exit((x-1)*m+y);
end;
procedure setl(x,y:longint);
begin
  inc(tot);
  next[tot]:=first[x];
  first[x]:=tot;
  endl[tot]:=y;
  inc(tot);
  next[tot]:=first[y];
  first[y]:=tot;
  endl[tot]:=x;
end;
procedure spfa;
var
  k,l:longint;
begin
   fillchar(dis,sizeof(dis),$3f);
   a[1]:=s; b[s]:=true;  dis[s]:=0;
   head:=0;tail:=1;
   repeat
     inc(head);
     b[a[head]]:=false;
     k:=first[a[head]]; l:=endl[k];
     while k<>0 do
     begin
       if dis[l]>dis[a[head]]+1 then
       begin
         dis[l]:=dis[a[head]]+1;
         if not b[l] then
         begin
           inc(tail);
           a[tail]:=l;
           b[l]:=true;
         end;
       end;
       k:=next[k];l:=endl[k];
     end;
   until head>=tail;
end;
begin
assign(input,'puzzle.in');reset(input);
assign(output,'puzzle.out');rewrite(output);
   readln(n,m,q);
   for i:=1 to n do
    for j:=1 to m do
    begin
      read(x);
      if x=1 then
      begin
        bo[i,j]:=true;
        if bo[i-1,j] then setl(cao(i,j),cao(i-1,j));
        if bo[i,j-1] then setl(cao(i,j),cao(i,j-1));
      end
        else bo[i,j]:=false;
    end;
   for i:=1 to q do
   begin
     ans:=0;
     readln(x,y,x1,y1,x2,y2);
     boo:=true;
     s:=cao(x2,y2);
     t:=cao(x,y);
     spfa; inc(ans,dis[t]);
     t:=cao(x1,y1);
     tt:=dis[t];
     ss:=abs(x1-x2)*abs(y1-y2)-1;
     if (x1=x)and(tt<>1) then
     begin
       dec(x);
       if y1<y then begin yy:=y1;yyy:=y;end else begin yy:=y;yyy:=y1;end;
       for j:=yy to yyy do
         if not bo[x,j] then
         begin
          boo:=false;
          break;
         end;
       inc(x,2);
       for j:=yy to yyy do
         if not bo[x,j] then
         begin
          boo:=false;
          break;
         end;
     end;
     if (y1=y)and(tt<>1) then
     begin
       dec(y);
       if x1<x then begin yy:=x1;yyy:=x;end else begin yy:=x;yyy:=x1; end;
       for j:=yy to yyy do
         if not bo[j,y] then
         begin
           boo:=false;
           break;
         end;
       inc(y,2);
       for j:=yy to yyy do
         if not bo[j,y] then
         begin
           boo:=false;
           break;
         end;
     end;
     if not boo then begin writeln('-1');continue;end;
     ans:=ans+ss*(tt-1)+tt;
     writeln(ans);
   end;
close(input);close(output);
end.
