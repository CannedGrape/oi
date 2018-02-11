program block;
  var i,n,x:longint;
      a,h:array[0..100000] of longint;

    procedure qujian(p,q:longint);
    begin
      for i:= p to q do
         if (a[i]=h[i]) and (i<>p) and(i<>q) then
            begin q:=i;qujian(p,q);qujian(q,n);end;

      while (a[p]=h[p]) and (p<q) do  inc(p);
      while (a[q]=h[q]) and (p<q) do dec(q);
      if a[p]<>h[p] then begin for i:= p to q do a[i]:=a[i]+1; x:=x+1;end;

     if (p<q) or ((p=q) and (a[q]<h[q])) then qujian(p,q);
     if (q<n) or ((q=n)and (a[q]<h[q])) then qujian(q,n);
    end;
begin
  assign(input,'block.in');
  assign(output,'block.out');
  reset(input);
  rewrite(output);
      readln(n);
    for i:=1 to n do read(h[i]);
    qujian(1,n);
    write(x);


  close(input);
  close(output);

end.
