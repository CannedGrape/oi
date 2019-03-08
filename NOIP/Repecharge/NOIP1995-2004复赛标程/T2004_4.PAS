program alpha(input,output);			
const maxn=26;			
type arr=array[1..maxn]of -1..maxn-1;			
     arrc=array[1..maxn]of char;			
var a,b,c:string;			
    haschar:array['A'..'Z']of boolean;			
    n,i,j,k:integer;			
    p,q,r:arr;			
    v:array['A'..'Z']of 0..maxn-1;			
    work:arrc;			
    used:array[0..maxn-1]of boolean;			
			
procedure out_put;			
var i:integer;			
begin			
    for i:=1 to n-1 do			
       write(v[chr(ord('A')+i-1)],' ');			
    writeln(v[chr(ord('A')+n-1)]);			
    close(output);			
    halt;			
end;			
			
function ok:boolean;			
var i,c:integer;flag:boolean;			
begin			
    flag:=true;i:=n;c:=0;			
    while flag and (i>=1) do			
        if (p[i]=-1) or (q[i]=-1) or (r[i]=-1) then break			
        else			
           if (c+p[i]+q[i]) mod n<>r[i] then flag:=false			
           else begin			
              c:=(c+p[i]+q[i]) div n;			
              i:=i-1;			
           end;			
    if (i=0 ) and (c<>0) then flag:=false;			
    ok:=flag;			
end;			
			
function check:boolean;			
var i,v1,v2:integer;flag:boolean;			
begin			
    flag:=true;i:=n;			
    while flag and (i>=1) do begin			
        if (p[i]<>-1) and (q[i]<>-1) and (r[i]<>-1) then			
           if ((p[i]+q[i]) mod n<>r[i]) and ((p[i]+q[i]+1) mod n<>r[i]) then			
               flag:=false			
        else if (p[i]<>-1) and (q[i]<>-1) and (r[i]=-1) then begin			
             v1:=(p[i]+q[i]) mod n;			
             if used[v1] and used[(v1+1) mod n] then flag:=false;end			
        else if (p[i]<>-1) and (q[i]=-1) and (r[i]<>-1) then begin			
             v1:=(r[i]-p[i]+n) mod n;			
             if used[v1] and used[(v1+n-1) mod n] then flag:=false;end			
        else if (p[i]=-1) and (q[i]<>-1) and (r[i]<>-1) then begin			
             v1:=(r[i]-q[i]+n) mod n;			
             if used[v1] and used[(v1+n-1) mod n] then flag:=false;end;			
        i:=i-1;			
    end;			
    check:=flag;			
end;			
			
procedure change(var p:arr;a:arrc;c:char;v:integer);			
var i:integer;			
begin			
     for i:=1 to n do			
         if a[i]=c then p[i]:=v;			
end;			
			
procedure try(i:integer);			
var j,k:integer;			
    p1,q1,r1:arr;			
begin			
     if i<=n then begin			
        if ok then			
           if check then			
               for j:=0 to n-1 do			
                  if not used[j] then begin			
                      used[j]:=true;			
                      v[work[i]]:=j;			
                      for k:=1 to n do begin p1[k]:=p[k];q1[k]:=q[k];r1[k]:=r[k];end;			
                      change(p,a,work[i],j);			
                      change(q,b,work[i],j);			
                      change(r,c,work[i],j);			
                      try(i+1);			
                      used[j]:=false;			
                      for k:=1 to n do begin p[k]:=p1[k];q[k]:=q1[k];r[k]:=r1[k];end;			
                   end;			
      end			
      else if ok then out_put;			
end;			
			
begin			
    assign(input,'alpha.in');			
    reset(input);			
    readln(n);			
    readln(a);readln(b);readln(c);			
    close(input);			
    fillchar(haschar,sizeof(haschar),false);			
    j:=0;			
    for i:=n downto 1 do begin			
       if not haschar[a[i]] then begin			
          j:=j+1;work[j]:=a[i];haschar[a[i]]:=true;end;			
       if not haschar[b[i]] then begin			
          j:=j+1;work[j]:=b[i];haschar[b[i]]:=true;end;			
       if not haschar[c[i]] then begin			
          j:=j+1;work[j]:=c[i];haschar[c[i]]:=true;end;			
    end;			
    if j<>n then begin writeln('Error data input');writeln('j=',j,' n=',n);halt;end;			
    for i:=1 to n do begin p[i]:=-1;q[i]:=-1;r[i]:=-1;used[i-1]:=false;end;			
    assign(output,'alpha.out');			
    rewrite(output);			
    try(1);			
end.			
