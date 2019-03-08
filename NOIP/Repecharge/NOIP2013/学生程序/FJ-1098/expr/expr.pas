var s:ansistring;
    i,j,k,l1,l2,zuo,you:qword;
    i2:integer;
    s2:string;
begin
  assign(input,'expr.in');
  assign(output,'expr.out');
  reset(input);
  rewrite(output);
  read(s);
  i:=0;
  while i<length(s) do
  begin
    i:=i+1;
    if s[i]='*' then
    begin
      k:=i-1;
      j:=k;
      while (j>=1)and(ord(s[j])>=48) do j:=j-1;
      j:=j+1;
      zuo:=j;
      val(copy(s,j,k-j+1),l1);
      k:=i+1;
      j:=k;
      while (j<=length(s))and(ord(s[j])>=48) do j:=j+1;
      j:=j-1;
      you:=j;
      val(copy(s,k,j-k+1),l2);
      l1:=l1*l2;
      l1:=l1 mod 10000;
      str(l1,s2);
      you:=you-zuo+1;
      delete(s,zuo,you);
      if s2<>'0' then insert(s2,s,zuo);
      i:=zuo+length(s2)-1;
    end;
  end;
  i:=0;
  while i<length(s) do
  begin
    i:=i+1;
    if s[i]='+' then
    begin
      k:=i-1;
      j:=k;
      while (j>=1)and(ord(s[j])>=48) do j:=j-1;
      j:=j+1;
      zuo:=j;
      val(copy(s,j,k-j+1),l1);
      k:=i+1;
      j:=k;
      while (j<=length(s))and(ord(s[j])>=48) do j:=j+1;
      j:=j-1;
      you:=j;
      val(copy(s,k,j-k+1),l2);
      l1:=l1+l2;
      l1:=l1 mod 10000;
      str(l1,s2);
      you:=you-zuo+1;
      delete(s,zuo,you);
      if s2<>'0' then insert(s2,s,zuo);
      i:=zuo+length(s2)-1;
    end;
  end;
  if length(s)>4 then for i2:=1 to 4 do write(s[length(s)-4+i2])
  else write(s);
  close(input);
  close(output);
end.
