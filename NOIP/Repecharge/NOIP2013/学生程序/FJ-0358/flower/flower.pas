var n,i,j,m,w:longint;
    b,h:array[1..100000] of longint;

    begin
     readln(n);
      for i:=1 to n do
       read(h[i]);
      fillchar(b,sizeof(b),0);
      b[1]:=1;

     for i:=2 to n do
      begin
       for j:=1 to i-1 do
        begin
        if b[j] mod 2=1 then
         if h[j]>h[i] then
          if (b[j]>b[i]-1) then b[i]:=b[j]+1;
       if b[j] mod 2 =0 then
        if h[j]<h[i] then
         if (b[j]>b[i]-1) then b[i]:=b[j]+1;
      end;end;
       m:=0;
     for i:= 1 to n do
      if m<b[i] then m:=b[i];


     for i:=2 to n do begin
      for j:=1 to i-1 do begin
       if b[j] mod 2=1 then

         if h[j]<h[i] then
          if b[j]>b[i]-1 then b[i]:=b[j]+1;

       if b[j] mod 2 =0 then
        if h[j]>h[i] then
         if b[j]>b[i]-1 then b[i]:=b[j]+1;
      end;end;
       w:=0;
     for i:= 1 to n do
      if w<b[i] then w:=b[i];

      if w<m then
     write(m) else write(w);
     end.