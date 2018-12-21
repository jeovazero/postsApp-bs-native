open BsReactNative;

let makePost = (author, text) =>
  Post.{author, text};

let posts = [|
  makePost("Xin", "The road is endless."),
  makePost("Gondar", "You can't fight what you can't see.")
|];

let createPostElement = (key, post) =>
  <Post key=string_of_int(key) post/>;

let app = () =>
  <ReasonApollo.Provider client=Client.instance>
    <View>
      <TitleBar />
      <View>
        (ReasonReact.array(Array.mapi(createPostElement, posts)))
      </View>
    </View>
    <GetPosts />
  </ReasonApollo.Provider>