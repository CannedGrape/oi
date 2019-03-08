var i,n,ans,max,l,j,k:longint;
    h,a:array[0..100001] of longint;

begin
  assign(input,'flower.in');
  assign(output,'flower.out');
  reset(input);
  rewrite(output);
  readln(n);
  for i:=1 to n do read(h[i]);
  ans:=0;
  max:=0;
  l:=0;
  for i:=1 to n do
    begin
      fillchar(a,sizeof(a),0);
      k:=1;
      a[1]:=h[i];
      for j:=i to n do
        begin
          if (k mod 2=0) then
            begin
              if h[j]>a[k] then
                begin
                  inc(k);
                  a[k]:=h[j];
                end;
            end
          else
            begin
              if h[j]<a[k] then
                begin
                  inc(k);
                  a[k]:=h[j];
                end;
            end;
        end;
      if k>max then max:=k;
    end;
  for i:=1 to n do
    begin
      fillchar(a,sizeof(a),0);
      k:=1;
      a[1]:=h[i];
      for j:=i to n do
        begin
          if (k mod 2=0) then
            begin
              if h[j]<a[k] then
                begin
                  inc(k);
                  a[k]:=h[j];
                end;
            end
          else
            begin
              if h[j]>a[k] then
                begin
                  inc(k);
                  a[k]:=h[j];
                end;
            end;
        end;
      if k>max then max:=k;
    end;
  writeln(max);
  close(input);
  close(output);
end.
