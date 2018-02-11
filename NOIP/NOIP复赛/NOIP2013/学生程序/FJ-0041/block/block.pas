program block;
var h:array[0.. 100001]of longint;
    be,la:array[0.. 100001]of longint;
    i,j,t,n,m,l,r,z,y,x:longint;
    procedure find(l,r,s:longint);
    var i,j,t,y,x:longint;
    begin
      if l>r then exit;
      if s>m then exit;
      t:=la[s];
      while t>r do t:=be[t];
      if t<l then
      begin
        find(l,r,s+1);
        inc(z);
      end
      else begin
        j:=r;
        inc(z);
        while t>=l do
        begin
          find(t+1,j,s+1);
          j:=t-1;
          t:=be[t];
        end;
        find(l,j,s+1);
      end;
    end;
begin
  assign(input,'block.in');
  reset(input);
  assign(output,'block.out');
  rewrite(output);
  readln(n);
  fillchar(be,sizeof(be),0);
  fillchar(la,sizeof(la),0);
  m:=0;
  for i:=1 to n do
  begin
    read(h[i]);
    if m<h[i] then m:=h[i];
    if la[h[i]]=0 then la[h[i]]:=i
    else begin
      be[i]:=la[h[i]];
      la[h[i]]:=i;
    end;
  end;
  z:=0;
  find(1,n,1);
  writeln(z);
  close(input);
  close(output);
end.
