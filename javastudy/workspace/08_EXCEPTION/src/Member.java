import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;
import lombok.ToString;

@NoArgsConstructor
@AllArgsConstructor
@Getter
@Setter
@ToString
public class Member {

	private String id;
	private String password;
	
	/*
	public Member() {  // @NoArgsConstructor
		
	}
	public Member(String id, String password) {  // @AllArgsConstructor
		super();
		this.id = id;
		this.password = password;
	}
	*/
	
}
