var n,i,j,ans:longint;
  a,b:array[1..100000]of longint;
  procedure swap1(i,j:longint);
    var t:longint;
    begin
      t:=a[i]; a[i]:=a[j]; a[j]:=t;
    end;
  procedure swap2(i,j:longint);
    var t:longint;
    begin
      t:=b[i]; b[i]:=b[j]; b[j]:=t;
    end;
  begin
    assign(input,'match.in');reset(input);
    assign(output,'match.out');rewrite(output);
    readln(n);
    for i:=1 to n do read(a[i]);
    readln;
    for i:=1 to n do read(b[i]);
    for i:=2 to n do
      for j:=i-1 downto 1 do
        if (a[i]-a[j])*(b[i]-b[j])<0 then
          begin
            if a[j]<a[i] then swap1(i,j)
            else swap2(i,j);
            ans:=ans+i-j+i-j-1;
            if ans>=99999997 then ans:=ans-99999997;
          end;
    write(ans);
    close(input);
    close(output);
  end.
