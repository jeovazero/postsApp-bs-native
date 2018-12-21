open BsReactNative;

[@bs.val] external setTimeout : (unit => unit, int) => float = "setTimeout";
let timer = (fn) => {
  ignore(setTimeout(() => fn(), 250));
};

let str = ReasonReact.string;

module AddPost = [%graphql
  {|
  mutation AddPost($author: String!, $text: String!) {
      addPost(author: $author, text: $text) {
          author
          text
          id
      }
  }
|}
];

let txt = (str) =>  <Text> { str } </Text>;

module AddPostMutation = ReasonApollo.CreateMutation(AddPost);

let component = ReasonReact.statelessComponent("AddPost");
/**onPost(); */
let make = (~onPost, ~author="anon", ~text, _children) => {
  ...component,
  render: _ =>
    <AddPostMutation>
      ...{
           (mutation, {result}) => {
             let addNewPostQuery = AddPost.make(~author, ~text,());
             <View>
                <PostButton
                  onPress={ () =>
                    mutation(
                      ~variables=addNewPostQuery##variables,
                      ~refetchQueries=[|"getAllPosts"|],
                      ()
                    )
                    |> ignore
                } />
                <Text style=Style.(style([textAlign(Center)]))>
              {  switch (result) {
                  | NotCalled =>
                    "NotCalled" |> str;
                  | Data(_) =>
                    timer(onPost);
                    "Post has been added!" |> str;
                  | Error(_) =>
                    "ERROR" |> str;
                  | Loading =>
                    "Loading" |> str;
                  };
              } </Text>
             </View>;
           }
         }
    </AddPostMutation>,
};