var n,i,j,k:longint;a:array[0..100005] of integer;
    ans:int64;
procedure qsort(l,r:longint);
var i,j:longint;m:integer;

begin
  i:=l;j:=r;m:=a[l];
  repeat
    while a[i]<m do inc(i);
    while a[j]>m do dec(j);
    if i<=j then begin
      a[0]:=a[i];
      a[i]:=a[j];
      a[j]:=a[0];
      inc(i);
      dec(j);
    end;
  until i>j;
  if (i<r) then qsort(i,r);
  if (l<j) then qsort(l,j);
end;

procedure find(o,p:longint);

begin
  qsort(o,p);
  inc(ans,a[p]);
end;

procedure devide(w,v:longint);
var i:longint;

begin
  i:=0;
  for i:=w to v do
    if (a[i]<a[i-1]) and (a[i]<a[i+1]) then begin
      dec(ans,a[i]);
      break;
    end;
  find(w,i);
  if i<n then
    devide(i+1,n);
end;


begin
   assign(input,'block.in');reset(input);
   assign(output,'block.out');rewrite(output);

  readln(n);
  ans:=0;

  for i:=1 to n do read(a[i]);
    //if a[i]>ma then ma:=a[i];


  a[0]:=0;
  k:=1;
  {for i:=1 to n do begin
    if ((a[i]<a[i-1]) and (a[i]<a[i+1])) or (i=n) then begin
      qsort(k,i);
      inc(ans,a[i]-a[k]);
      k:=i+1;
    end;
  end;}

  devide(1,n);
  writeln(ans);

  close(input);
  close(output);
end.
