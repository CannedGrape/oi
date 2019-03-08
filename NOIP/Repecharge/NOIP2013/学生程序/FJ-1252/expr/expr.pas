program ex1;
  var a:array[1..100000]of string;
       t,h,j,i,t1,k:longint;
       ans,l1,l2,k1:int64;
       n,ans1,ans2:string;
    begin
     assign(input,'expr.in'); reset(input);
     assign(output,'expr.out'); rewrite(output);
     readln(n);
     t:=0;
     j:=0;
     h:=1;
     repeat
       inc(t);
       if (n[t]='+')or(n[t]='*') then begin
        inc(j);
        for k:=h to t-1 do
         a[j]:=a[j]+n[k];
        inc(j);
        a[j]:=n[t];
        h:=t+1;
        end;
       until t=length(n);
           inc(j);
        for k:=h to length(n) do
          a[j]:=a[j]+n[k];
        for i:=1 to  j do
          if (a[i]='*')and(k>=i) then
            repeat
            val(a[i-1],l1);
            val(a[i+1],l2);
              str(l1*l2,a[i-1]);
              for k:=i to j-2 do
              a[k]:=a[k+2];
              dec(j,2);
              k:=j;
            until (a[i]<>'*')or(i>=j);
            ans:=0;
       for i:=1 to j do
       if a[i]<>'+' then
           begin
             val(a[i],k1);
             ans:=(ans+k1) mod 10000;
           end;
       str(ans,ans1);
       writeln(ans1);
        if length(ans1)<=4 then  writeln(ans1)
        else
          begin
         ans2:=copy(ans1,length(ans1)-3,length(ans1));
          for i:=1 to 4 do
            if ans2[i]<>'0' then
              begin
               for j:=i to 4 do
                 write(ans2[j]);
            close(input); close(output);
            halt;
            end;
         end;
     close(input); close(output);
   end.
