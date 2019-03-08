var tot,i,j,n,k,de,time,right,left:longint;
    a,num,wh:array[0..100005]of longint;

procedure kp(l,r:longint);
var i,j,m,t:longint;
begin
  i:=l;j:=r;m:=a[(i+j) shr 1];
  repeat
    while a[i]<m do  inc(i);
    while a[j]>m do dec(j);
    if i<=j then
      begin
        t:=a[i];a[i]:=a[j];a[j]:=t;
        t:=wh[i];wh[i]:=wh[j];wh[j]:=t;
        inc(i);dec(j);
      end;
  until i>j;
  if i<r then kp(i,r);
  if l<j then kp(l,j);
end;

begin
assign(input,'block.in');reset(input);
assign(output,'block.out');rewrite(output);
  readln(n);
  tot:=0;
  for i:=1 to n do
    begin
      read(a[i]);
      tot:=tot+a[i];
      num[i]:=a[i];
      wh[i]:=i;
    end;
  kp(1,n);
  k:=1;
  for k:=1 to n do
    if num[wh[k]]<>0 then
      begin
        left:=wh[k];
        right:=wh[k]+1;
        de:=num[wh[k]];
        time:=time+de;
        while num[left]<>0 do
          begin
            num[left]:=num[left]-de;
            dec(left);
            tot:=tot-de;
          end;
        while num[right]<>0 do
          begin
            num[right]:=num[right]-de;
            inc(right);
            tot:=tot-de;
          end;
        if tot=0 then break;
      end;
  writeln(time);
  close(input);
  close(output);
end.
