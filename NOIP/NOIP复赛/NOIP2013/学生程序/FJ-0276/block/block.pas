var
  i,n,h,t,long,ac:longint;
  a,s:array[0..100100] of longint;

begin
  assign(input,'block.in'); reset(input);
  assign(output,'block.out'); rewrite(output);
  fillchar(a,sizeof(a),0);
  fillchar(s,sizeof(s),0);
  read(n);
  for i:= 1 to n do read(a[i]);

  h:=0; t:=0; ac:=0;
  while h<n+1 do
  begin
    inc(h);
    if a[h]<s[t] then
    begin
      long:=s[t];
      while a[h]<s[t] do dec(t);
      inc(ac,long-a[h]);
    end;
    inc(t); s[t]:=a[h];
  end;

  write(ac);
  close(input); close(output);
end.
