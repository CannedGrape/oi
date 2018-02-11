var n,min,i,ans,kk,t:longint; bo,pp:boolean;
    h,a:array[0..100000]of longint;
begin
  assign(input,'block.in'); reset(input);
  assign(output,'block.out'); rewrite(output);
  readln(n);
  min:=maxlongint;
  bo:=false;
  fillchar(h,sizeof(h),0);
  for i:=1 to n do
  begin
    read(h[i]);
    if h[i]<min then min:=h[i];
  end;
  for i:=1 to n do h[i]:=h[i]-min;

  repeat

    t:=0; a[t]:=0;

    for i:=1 to n do if h[i]=0 then
    begin inc(t); a[t]:=i; end;
    a[t+1]:=n+1;

    kk:=0;
    repeat
      min:=maxlongint; pp:=false;
      for i:=a[kk] to a[kk+1] do
      if (h[i]>0)and(h[i]<min) then min:=h[i];
      for i:=a[kk] to a[kk+1] do
      if h[i]>0 then
      begin
        h[i]:=h[i]-min;
        pp:=true;
      end;
      if pp then inc(ans,min);
      inc(kk);
    until kk>t;

    bo:=true;
    for i:=1 to n do if h[i]<>0 then begin bo:=false; break; end;
  until bo;
  writeln(ans+1);
  close(input); close(output);
end.
