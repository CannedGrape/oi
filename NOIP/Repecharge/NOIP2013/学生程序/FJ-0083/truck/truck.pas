program truck;
const filename='truck';
maxn=10000;maxm=50000;maxt=100000;
inv=maxlongint div 3;
var n,m,qt,i,j,s,t:longint;
ans,temp:longint;

x,y,z,num:longint;
v:array[1..maxn]of longint;
fto,next,c:array[1..maxm shl 1]of longint;

dis:array[1..maxn,1..maxn]of longint;
dis2:array[1..maxn]of longint;

head,tail,now,aim:longint;
q:array[1..maxt]of longint;
inq:array[1..maxn]of boolean;

begin
  assign(input,filename+'.in');reset(input);
  assign(output,filename+'.out');rewrite(output);

  read(n,m);
  for i:=1 to m do
    begin
      read(x,y,z);

      inc(num);
      next[num]:=v[x];
      fto[num]:=y;
      c[num]:=z;
      v[x]:=num;

      inc(num);
      next[num]:=v[y];
      fto[num]:=x;
      c[num]:=z;
      v[y]:=num;
    end;

  for i:=1 to n-1 do begin
    fillchar(inq,sizeof(inq),#0);
    head:=1;tail:=2;
    q[1]:=i;inq[i]:=true;
    for j:=1 to n do begin
      if i=j then continue;
      dis2[j]:=dis[i,j];
      if dis[i,j]>0 then begin
        q[tail]:=j;
        inq[j]:=true;
        inc(tail);
      end;
    end;
    dis2[i]:=inv;
    while head<>tail do begin
      now:=q[head];
      j:=v[now];
      while j>0 do begin
        aim:=fto[j];
        if dis2[now]<c[j] then temp:=dis2[now]
        else temp:=c[j];
        if (temp>dis2[aim]) then begin
          dis2[aim]:=temp;
          if not(inq[aim]) then begin
            q[tail]:=aim;
            inq[aim]:=true;
            inc(tail);
            if tail>maxt then tail:=1;
          end;
        end;
        j:=next[j];
      end;
      inc(head);
      if head>maxt then head:=1;
    end;
    for j:=1 to n do begin
      dis[i,j]:=dis2[j];
      dis[j,i]:=dis2[j];
    end;
  end;

  readln(qt);
  while qt>0 do begin
    read(s,t);

    ans:=dis[s,t];
    if ans>0 then
      writeln(ans)
    else
      writeln('-1');
    dec(qt);
  end;

  close(input);close(output);
end.
