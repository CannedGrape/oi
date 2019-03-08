program block;
const maxn=100000;maxt=262144;
var n,m:longint;
i,j,k:longint;
temp:longint;
t:array[1..maxt]of longint;
l,r:array[0..20]of longint;
ans:int64;

function lowbit(p:longint):longint;
begin
  exit(p and (-p));
end;

begin
  assign(input,'block.in');reset(input);
  assign(output,'block.out');rewrite(output);

  readln(n);
  m:=1;j:=0;
  while m<n+2 do begin
    m:=m shl 1;
    inc(j);
  end;

  for i:=1 to n do
    read(t[m+i]);

  for i:=m-1 downto 1 do begin
    if t[i shl 1]<t[i shl 1+1] then
      temp:=t[i shl 1]
    else
      temp:=t[i shl 1+1];
    t[i]:=temp;
    dec(t[i shl 1],temp);
    dec(t[i shl 1+1],temp);
  end;
  ans:=0;
  for i:=1 to m+n do begin
    while t[i]>0 do begin
      l[0]:=0;r[0]:=0;
      if i-lowbit(i)>0 then begin
        l[1]:=i-1;
        inc(l[0]);
        while (t[l[1]]=0)and(l[1]<m) do
          l[1]:=l[1] shl 1+1;
        while t[l[l[0]]]>0 do begin
          inc(l[0]);
          if l[l[0]-1]-lowbit(l[l[0]-1])>0 then begin
            l[l[0]]:=l[l[0]-1]-1;
            while (t[l[l[0]]]=0)and(l[l[0]]<m) do
              l[l[0]]:=l[l[0]] shl 1+1;
          end
          else l[l[0]]:=m;
        end;
        dec(l[0]);
      end;
      if i+1-lowbit(i+1)>0 then begin
        r[1]:=i+1;
        inc(r[0]);
        while (t[r[1]]=0)and(r[1]<m) do
          r[1]:=r[1] shl 1;
        while t[r[r[0]]]>0 do begin
          inc(r[0]);
          if r[r[0]-1]+1-lowbit(r[r[0]-1]+1)>0 then begin
            r[r[0]]:=r[r[0]-1]+1;
            while (t[r[r[0]]]=0)and(r[r[0]]<m) do
              r[r[0]]:=r[r[0]] shl 1;
          end
          else r[r[0]]:=m+n+1;
        end;
        dec(r[0]);
      end;
      temp:=t[i];
      if l[0]>0 then begin
        for j:=1 to l[0] do begin
          if t[l[j]]<temp then temp:=t[l[j]];
        end;
      end;
      if r[0]>0 then begin
        for j:=1 to r[0] do begin
          if t[r[j]]<temp then temp:=t[r[j]];
        end;
      end;
      dec(t[i],temp);
      if l[0]>0 then begin
        for j:=1 to l[0] do begin
          dec(t[l[j]],temp);
        end;
      end;
      if r[0]>0 then begin
        for j:=1 to r[0] do begin
          dec(t[r[j]],temp);
        end;
      end;
      inc(ans,temp);
      {
      writeln('i=',i);
      writeln('ans=',ans);
      for l:=0 to j do begin
        for k:=1 shl l to 1 shl (l+1)-1 do
          write(t[k],' ');
        writeln;
      end;
      }
    end;
  end;

  write(ans);

  close(input);close(output);
end.
