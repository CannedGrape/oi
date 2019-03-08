program match;
var n,i,j,k,couple:longint;
      line1,line2,oldpart,newpart,quepart:array[-10..200010]of longint;

procedure qsort1(vl,vr:longint);
var vp,vq,mid,tmp:longint;
begin
     vp:=vl;vq:=vr;mid:=line1[vl+random(vr-vl+1)];
     repeat
		 while line1[vp]<mid do inc(vp);
		 while line1[vq]>mid do dec(vq);
		 if (vp<=vq) then 
			 begin
		         tmp:=line1[vp];line1[vp]:=line1[vq];line1[vq]:=tmp;
		         inc(vp);dec(vq);
	         end;
	 until (vp>vq);
	 if (vl<vq) then qsort1(vl,vq);
	 if (vp<vr) then qsort1(vp,vr);
end;

procedure qsort2(vl,vr:longint);
var vp,vq,mid,tmp:longint;
begin
     vp:=vl;vq:=vr;mid:=line2[vl+random(vr-vl+1)];
     repeat
		 while line2[vp]<mid do inc(vp);
		 while line2[vq]>mid do dec(vq);
		 if (vp<=vq) then 
			 begin
		         tmp:=line2[vp];line2[vp]:=line2[vq];line2[vq]:=tmp;
		         inc(vp);dec(vq);
	         end;
	 until (vp>vq);
	 if (vl<vq) then qsort2(vl,vq);
	 if (vp<vr) then qsort2(vp,vr);
end;


begin
     assign(input,'match.in');reset(input);
	 assign(output,'match.out');rewrite(output);
	 readln(n);
	 for i:=1 to n do
		 read(line1[i]);
	 for i:=1 to n do
		 read(line2[i]);
	 for i:=1 to n do
		 oldpart[line1[i]]:=line2[i];
	 qsort1(1,n);
	 qsort2(1,n);
	 for i:=1 to n do
		 newpart[line1[i]]:=line2[i];
	 k:=0;
	 couple:=0;
	 fillchar(quepart,sizeof(quepart),0);
	 for i:=1 to n do
		 if (oldpart[i]<>newpart[i]) then
			 begin
		         inc(k);
		         quepart[newpart[i]]:=oldpart[i];
		     end;
	 for i:=1 to n do
		 if (i=quepart[quepart[i]])then inc(couple);
	 if (couple=k) then k:=k div 2
		 else begin
        	 couple:=couple div 2;
        	 k:=k-couple-1;
		   end;
	 k:=k mod 99999997;
	 writeln(k);
     close(input);
	 close(output);
end.