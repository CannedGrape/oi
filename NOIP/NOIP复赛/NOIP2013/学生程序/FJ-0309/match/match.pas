program jk;
var i,n,j,k,ans :longint;
    a,b,c,d:array[0..100000]of int64;
  procedure sorta(l,r:longint);
  var i,j:longint;mid,t:int64;
    begin
      i:=l;j:=r;mid:=a[(i+j)shr 1];
      repeat
       while a[i]<mid do inc(i);
       while a[j]>mid do dec(j);
       if i<=j then
         begin
            t:=a[i];a[i]:=a[j];a[j]:=t;
            inc(i);dec(j);                  end;
      until i>j;
      if i<r then sorta(i,r);
      if l<j then sorta(l,j);
    end;

  procedure sortb(l,r:longint);
  var i,j:longint;mid,t:int64;
    begin
      i:=l;j:=r;mid:=b[(i+j)shr 1];
      repeat
       while b[i]<mid do inc(i);
       while b[j]>mid do dec(j);
       if i<=j then
         begin
            t:=b[i];b[i]:=b[j];b[j]:=t;
            inc(i);dec(j);                  end;
      until i>j;
      if i<r then sortb(i,r);
      if l<j then sortb(l,j);
    end;

  begin
    assign(input,'match.in');reset(input);
    assign(output,'match.out');rewrite(output);
    read(n);
    for i:=1 to n do begin read(a[i]);c[i]:=a[i]; end;
    for i:=1 to n do begin read(b[i]);d[i]:=b[i]; end;
    sorta(1,n);sortb(1,n);   ans:=0;
    for i:=1 to n do
      begin
        for j:=1 to n do if a[j]=c[i] then break;
        for k:=1 to n do if b[j]=d[k] then break;
        ans:=ans+(k-i);
        for j:=k downto i+1 do d[j]:=d[j-1];d[i]:=0;
      end;
    write(ans);
    close(input);close(output);
  end.







