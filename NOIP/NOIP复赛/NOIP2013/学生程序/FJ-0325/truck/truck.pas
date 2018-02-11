var next,last,v,z,f:array[0..200000]of longint;
    i,j,a,b,c,m,n,ans,l,r,t,q,maxr,mid,x,y:longint;
    o,h:array[0..10000]of boolean;
function check(w,z1,z2:longint):boolean;
var i,j,k,s,t:longint;
begin
  fillchar(f,sizeof(f),0);
  fillchar(o,sizeof(o),1);
  s:=1; t:=0; f[1]:=z1; o[z1]:=false;
  while s>t do
    begin
      inc(t);
      j:=last[f[t]];
      while j<>0 do
        begin
          if (z[j]>=w)and(o[v[j]]) then
            begin
              o[v[j]]:=false;
              inc(s);
              f[s]:=v[j];
              if f[s]=z2 then exit(true);
            end;
          j:=next[j];
        end;
    end;
  exit(false);
end;

begin
  assign(input,'truck.in'); reset(input);
  assign(output,'truck.out');  rewrite(output);
  readln(n,m);  maxr:=0; t:=0;
  fillchar(h,sizeof(h),0);
  for i:=1 to m do
    begin
      readln(a,b,c);
      h[a]:=true; h[b]:=true;
      if c>maxr then maxr:=c;
      inc(t);
      next[t]:=last[a];
      last[a]:=t;
      v[t]:=b;
      z[t]:=c;
      inc(t);
      next[t]:=last[b];
      last[b]:=t;
      v[t]:=a;
      z[t]:=c;
    end;
  readln(q);
  for i:=1 to q do
    begin
      readln(x,y);
      if (h[x]=false)or(h[y]=false) then begin writeln(-1); continue; end;
      l:=0; r:=maxr; ans:=-1;
      while l<=r do
        begin
          mid:=(l+r) shr 1;
          if check(mid,x,y) then
            begin ans:=mid; l:=mid+1; end else r:=mid-1;
        end;
      writeln(ans);
    end;
  close(input);  close(output);
end.


