var
  b,c,w,n,m,s,e,i,j,k,l,ans:integer;
  a:array[1..1000,1..1000]of integer;

begin
  assign(input,'level.in');
  assign(output,'level.out');
  reset(input);
  rewrite(output);
  fillchar(a,sizeof(a),1);
  readln(n,m);
  ans:=1;
  read(w);
  for i:=1 to w do
    read(a[1,i]);
  readln;
  for i:=a[1,1] to a[1,w] do
    if i<>a[1,i] then
    begin
      ans:=2;
      break;
    end;
  for i:=2 to m do
  begin
    read(s);
    for j:=1 to s do
      read(a[i,j]);
    readln;
    for j:=1 to w do
      if a[i,1]=a[i-1,j] then
      begin
        b:=j-1;
        if w>s then
        begin
          for k:=1 to s do
            if a[i-1,k+b]<>a[i,k] then
            begin
              if a[i-1,k+b]>a[i,k] then
              begin
                for l:=w downto k do
                begin
                  a[i-1,l+1+b]:=a[i-1,l+b];
                  a[i-1,k+b]:=a[i,k];
                end;
              end else
              begin
                for l:=s downto k do
                begin
                  a[i,l+1]:=a[i,l];
                  a[i,k]:=a[i-1,k+b];
                end;
              end;
              inc(ans);
              break;
            end;
        end else
        begin
          for k:=1 to w do
            if a[i-1,k+b]<>a[i,k] then
            begin
              if a[i-1,k+b]>a[i,k] then
              begin
                for l:=w downto k do
                begin
                  a[i-1,l+1+b]:=a[i-1,l+b];
                  a[i-1,k+b]:=a[i,k];
                end;
              end else
              begin
                for l:=s downto k do
                begin
                  a[i,l+1]:=a[i,l];
                  a[i,k]:=a[i-1,k+b];
                end;
              end;
              inc(ans);
              break;
            end;
        end;
        break;
      end;
  end;
  writeln(ans);
  close(input);
  close(output);
end.
